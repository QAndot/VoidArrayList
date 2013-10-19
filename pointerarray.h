#ifndef POINTERARRAY_H
#define POINTERARRAY_H
#define DEF_SIZE (10)
#define DELTA (4)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;



typedef
int (*TCmpFunc)(void*, string);

template <class T>
class pointerArray {
public:
    pointerArray(int initialSize = DEF_SIZE){
           this->start = new void* [initialSize]; /* запрашиваем память для  нового массива*/
           this->initArr(initialSize);
    }
    void showList();
    bool delFromList(int posDel);
    int findElList(string key, TCmpFunc cmpF,bool &findOK);
    void addToSort(void* pnew, int posAdd);
    void replaceSort(int delPos, void* newEl, int inPos);
    void clearAll();
    bool delAllList(bool delPointers);
    void expandDef(int sizeOld, int incSize);
    void** getStart() {
        return this->start;
    };
    int getSize() {
        return this->size;
    };
    int getCount() {
        return this->count;
    }
    void* getElem(int posEl) {
        return this->start[posEl];
    }
    ~pointerArray() {
        this->delAllList(true);
    };

protected:
    int size;
    int count;
    void** start;
    void initArr(int initSize);
 
};

 template<class T> void pointerArray<T>::initArr(int initSize) {
    this->count = 0; /*Заполняем служебный элемент массива – количество элементов списка*/

    this->size = initSize; /*Заполняем служебыій элемент массива – размер массива */
}

 template<class T> void pointerArray<T>::expandDef(int sizeOld, int incSize = DELTA) {

    int sizeNew = sizeOld + incSize;
    void** arOld = this->start; /*вспомогательный бестиповый указатель на начало массива указателей*/
    this->start = new void* [sizeNew]; /*выделение места для нового массива*/


    for (int i = sizeOld-1; i >= 0; i--) {
        this->start[i] = arOld[i];
    }
    this->size = sizeNew;

    delete []arOld;
}
 
 template<class T> int pointerArray<T>::findElList(string key,TCmpFunc cmpF,bool &findOK) {

    int posFndEl;
    int middl; /*middl выступает как индекс среднего элемента
              массива*/
    int hi, low; /*текущие границы - верхняя, нижняя*/ /*элемент не найден*/

    /*берем из мссива значение служебного элемента cunt
      И проверяем пуст ли список*/

    if (this->count == 0) {
        posFndEl = 0;
        return posFndEl;
    }
    /*Устанавливаем границы поиска на границы массива*/
    low = 0;
    hi = this->count - 1;
    
    do {
        
      middl = (hi + low) / 2 ; /*индекс среднего элемента*/
    
    /*Вызов функции сравнения при помощи указателя на функцию*/
    
   int   resultCompare= cmpF(this->start[middl], key); 
    
      if (resultCompare== 0)
        { posFndEl = middl; /*Элемент найден*/
		findOK = true;      /*элемент найден*/
		return posFndEl;
        }
     if (resultCompare == 1)
        {
          hi = middl - 1;  
	   }
     else 
        {
         low = middl + 1;
	   } 
	

    } while (low <= hi);
    findOK = false;
    posFndEl = low;
    return posFndEl; /*Перебран весь массив. Искомый элемент не найден. Определена позиция возможной вставки нового элемента*/
}
 
 template<class T> void pointerArray<T>::replaceSort(int delPos, void* newEl,int inPos) {
    this->delFromList(delPos);
    this->addToSort(newEl,inPos);
}
 
 template<class T> void pointerArray<T>::clearAll() {
    this->delFromList(0);
}

 template<class T> bool pointerArray<T>::delFromList(int posDel) {
    int cnt = this->count;
    if ((posDel < 0) || (posDel>cnt)) {
        return false;
    }
    delete (T*)(this->start[posDel]);
    for (int k = posDel; k < cnt - 1; k++) {
        this->start[k] = this->start[k + 1];
    }
    cnt--;
    this->count = cnt;
}

 template<class T> bool pointerArray<T>::delAllList(bool delPointers) {
    int cnt = this->count;
    if ((cnt==0) && (!delPointers)) {
        return false;
    }
    for (int i=0;i<cnt-1;i++) {
        delete (T*)(this->start[i]);
    }
    if (delPointers) {
        delete []this->start;
        this->start = NULL;
        this->size = 0;
        
    }
    this->count = 0;
    return true;
}

 template<class T> void pointerArray<T>::addToSort(void* pnew, int posAdd) {
    /*
         start – указатель на список
         pnew – указатель на новый элемент списка, который размещен
                     в памяти  и поля его заполнены
         posAdd – индекс элемента в массиве, в который необходимо вставить
                         указатель на новый элемент
     */

    int cnt = this->count;
    int sz = this->size;

    //если массив переполнен, то вызываем расширение массива
    if (cnt == sz) {
        this->expandDef(this->size);
    }


    if (posAdd == cnt) //добавляемый элемент располагается в конце списка
    {
        this->start[posAdd] = pnew;
    } else { // сдвиг элементов в массиве указателей на 1 вправо
        for (int k = cnt - 1; k >= posAdd; k--) {
            this->start[k + 1] = this->start[k];
        }
        this->start[posAdd] = pnew;
    }
    cnt++;

    this->count = cnt;
}

#endif // POINTERARRAY_H
