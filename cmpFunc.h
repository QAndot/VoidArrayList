/* 
 * File:   cmpFunc.h
 * Author: CROSP
 *
 * Created on October 17, 2013, 12:50 PM
 */

#ifndef CMPFUNC_H
#define	CMPFUNC_H
#include <string>
#include "pointerarray.h"
using namespace std;
struct TChair {
                    string name;
                    string fiozavkaf;
                    string telnumber;
public:
    TChair () {
        this->name = this->fiozavkaf = this->telnumber = " ";
    }
                } ;
struct TFaculty {
                   string name;
                   string fiodec;
                   string telnumber;
                   bool subInit;
                   int test;
                   pointerArray<TChair> *sublev;  // указатель на подсписок кафедр
public: TFaculty () {
        this->name = fiodec = telnumber = " ";
        this->subInit = false;
       this->sublev = 0;
       this->test = 13;
       cout<<"In TFaculty constructor"<<"\n";
}
                } ;
 struct TUniver {
                   string name;
                   string fiorec;
                   string telnumber;
                   bool subInit;
                   pointerArray<TFaculty> *sublev;  // указатель на подсписок факультетов
 public:    TUniver () {
            this->name = this->fiorec = this->telnumber = " ";
            this->subInit = false;
            this->sublev = 0; 
            cout<<"In TUniver constructor"<<"\n" ;
        }            

 } ;


     int cmpFact(void *p, string key);
     int cmpUniv(void *p, string key);
     int cmpChr(void *p, string key);

#endif	/* CMPFUNC_H */

