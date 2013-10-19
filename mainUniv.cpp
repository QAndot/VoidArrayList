/* 
 * File:   mainUniv.cpp
 * Author: CROSP
 * 
 * Created on October 16, 2013, 8:50 PM
 */

#include "mainUniv.h"

mainUniv::mainUniv() {
    this->univPoint = 0;
}

bool mainUniv::addUniv(void* pNew, string name) {
    bool success;
    this->univPoint->addToSort(pNew,this->univPoint->findElList(name, cmpUniv, success));
}

void* mainUniv::getUniv(string name, bool &findOk) {
    int posUniv = (this->univPoint->findElList(name, cmpUniv, findOk));
    if (findOk) {
        return (this->univPoint->getElem(posUniv));
       
    }
    else return 0;
}

        void* mainUniv::getFaculty(void* unPoint, string facName,bool &findOk) {
            TUniver * tmpUn = (TUniver*)unPoint;
            if (tmpUn->subInit) {
               int fndPos = tmpUn->sublev->findElList(facName, cmpFact,findOk);
               if (findOk) {
            return tmpUn->sublev->getElem(fndPos);
        }
        else {
            return 0;
        }
    }
  }
          void* mainUniv::getChair(void* unFac, string facName,bool &findOk) {
            TFaculty *tmpFac = (TFaculty*)unFac;
            if (tmpFac->subInit) {
               int fndPos = tmpFac->sublev->findElList(facName, cmpFact,findOk);
               if (findOk) {
            return tmpFac->sublev->getElem(fndPos);
        }
        else {
            return 0;
        }
    }
  }

bool mainUniv::addFaculty(void* pNew, void *univP, string facName) {
       TUniver *tmpUniv = (TUniver*)(univP);
            bool findFac = false;
            if (!(tmpUniv->subInit)) {
            this->initFac(tmpUniv);
            }
            tmpUniv->sublev->addToSort(pNew, tmpUniv->sublev->findElList(facName, cmpFact, findFac));
            return true;
    }
    bool mainUniv::initFac(void* tmpUn) {
        TUniver* tnp =(TUniver*)tmpUn;
        tnp->sublev= new pointerArray<TFaculty>();
        tnp->subInit = true;
        return true;
    }

    pointerArray<TUniver>* mainUniv::getUnivStart() {
        return this->univPoint;
    }   

    bool mainUniv::initChair(void* fac) {
        TFaculty* tmpFac = (TFaculty*)(fac);
        tmpFac->sublev = new pointerArray<TChair>();
        tmpFac->subInit = true;
        return true;
    }
    bool mainUniv::addChair(void* fac,void *pnew,string name) {
        TFaculty *tmpFac = (TFaculty*)fac;
        bool findOk;
         if (!(tmpFac->subInit)) {
            this->initChair(tmpFac);
            }
        tmpFac->sublev->addToSort(pnew,tmpFac->sublev->findElList(name,cmpChr,findOk));
    }
        void ** mainUniv::createUnivArr(int inSize) {
            this->univPoint = new pointerArray<TUniver>(inSize);
            return this->univPoint->getStart();
        }

        void mainUniv::delChair(void *pFac,int delPos) {
            TFaculty *tmpF = (TFaculty*)pFac;
            tmpF->sublev->delFromList(delPos);
            
        }
        bool mainUniv::delFaculty(void *pUniv,string delFac)
        {
            TUniver* tmpUn = (TUniver*)pUniv;
            if (!tmpUn->subInit) {
                return false ;
            }
            bool find;
            TFaculty *tmpFac =(TFaculty*)this->getFaculty(pUniv,delFac,find);
            if (!find) {
                return false;
            }
            if (tmpFac->subInit) {
                this->delAllChairs(tmpFac,true);
            }
            tmpUn->sublev->delFromList(tmpUn->sublev->findElList(delFac,cmpFact,find));
            return true;
        }
        bool mainUniv::delAllFaculties(void *pUniv,bool delPointers) {
            TUniver *tmpUn = (TUniver*)pUniv;
            if (tmpUn->subInit) {
                int cnt = tmpUn->sublev->getCount();
                TFaculty* tmFac;
                for (int i=0;i<cnt;i++) {
                    tmFac =(TFaculty*)(tmpUn->sublev->getElem(i));
                    if (tmFac->subInit) {
                    this->delAllChairs(tmFac,true);
                    }
                }
                    tmpUn->sublev->delAllList(delPointers);
                    if (delPointers) {
                        delete tmpUn->sublev;
                        tmpUn->subInit = false;
                    }
            } else 
            {return false;}
        }
         bool mainUniv::delAllChairs(void *pFac,bool delPointers) {
           TFaculty *tmpF = (TFaculty*)pFac;
            tmpF->sublev->delAllList(delPointers);
            if (delPointers) {
            delete tmpF->sublev;
            tmpF->subInit = false;
            }   
         }
         bool mainUniv::delAllUniver(bool delPointers) {
             if (!this->univPoint) {
             return false;
             }
             int unCnt = this->univPoint->getCount();
             for (int i=0;i<unCnt;i++) {
                 this->delAllFaculties(this->univPoint->getElem(i),true);
             }
             this->univPoint->delAllList(delPointers);
             if (delPointers){ 
                 delete this->univPoint;
             }
         }
         bool mainUniv::delUniv(string name) {
             if (!this->univPoint) {
                 return false;
             }
             bool fndOk;
             int delPos = this->univPoint->findElList(name,cmpUniv,fndOk);
             if (fndOk) {
                 this->delUniv(delPos);
                 return true;
             } else return false;
             
         }
         bool mainUniv::delUniv(int delPos) {
             TUniver *unDel = (TUniver*)this->univPoint->getElem(delPos);
             if(unDel->subInit) {
                 this->delAllFaculties(unDel,true);
             }
             this->univPoint->delFromList(delPos);
             return true;
         }
        