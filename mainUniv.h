/* 
 * File:   mainUniv.h
 * Author: CROSP
 *
 * Created on October 16, 2013, 8:50 PM
 */

#ifndef MAINUNIV_H
#define	MAINUNIV_H
#include "cmpFunc.h"




class mainUniv {
public:
    mainUniv();
    void ** createUnivArr(int inSize);
    bool addUniv(void* pNew,string name);
    bool addFaculty(void* pNew, void *univP, string facName);
    void* getFaculty(void* unPoint, string facName,bool &findOk);
    void delChair(void *pFac,int delPos);
    bool delUniv(string name);
    bool delFaculty(void *pUniv,string delFac);
    bool delAllChairs(void *pFac,bool delPointers);
    bool initFac(void * mpUn);
    bool initChair(void* fac);
    void* getUniv(string name,bool &findOk);
    bool addChair(void* fac,void *pnew,string name);
    void showUniversities();
    bool delAllFaculties(void *pUniv,bool delPointers);
    void* getChair(void* unFac, string facName,bool &findOk);
    pointerArray<TUniver>* getUnivStart();
    bool delAllUniver(bool delPointers);
    bool delUniv(int delPos);
private:
    pointerArray<TUniver>* univPoint ;
};

#endif	/* MAINUNIV_H */

