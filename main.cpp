#include "mainUniv.h"
#include "extrafunc.h"

int main(int argc, char** argv) {
    showWelcome();
    int choice;
    int initCount = 0;
    mainUniv univer;
    bool created = 0;
        showHelp();
    for(;;) {
        startPoint:
        showQuestion();
        cin.exceptions(istream::failbit | istream::badbit);
        try {
        cin>>choice;
        }
        catch (istream::failure e) {
            sayWrongInput();
            cin.clear();
            cin.ignore();
        }
        if (choice==1) {
            if (initCount>=1) {
                sayToDel();
            }
             askSize();
            int inSize;
            cin >> inSize;
            univer.createUnivArr(inSize);
            created = true;
            initCount++;
        }else if (choice==2){
                if (!created) {
                   sayCreateList();
                   goto startPoint;
                }
                string nameUn;
                TUniver* pnew = new TUniver();
                sayToEnterUnivName();
                cin>>nameUn;
                 sayToEnterUnivFiorec();
               cin>>(pnew->fiorec);
                sayToEnterUnivTel();
                cin>>(pnew->telnumber);
                pnew->name = nameUn;
                univer.addUniv(pnew,nameUn);
               
        } else if(choice==3) {
                if (!created) {
                   sayCreateList();
                    goto startPoint;
                }
               pointerArray<TUniver>* tmpUn = univer.getUnivStart();
               int count = tmpUn->getCount();
               TUniver *pUn;
               for (int i=0;i<count;i++) {
                   pUn =(TUniver*)tmpUn->getElem(i);
                   cout<<pUn->name<<NXLN;
                   cout<<pUn->fiorec<<NXLN;
                   cout<<pUn->telnumber<<NXLN;
               }
                
        }else if (choice==4) {
                if (!created) {
                   sayCreateList();
                    goto startPoint;
                }
                string univName;
                string facName;
                bool success = false;
                
                TFaculty *pnew = new TFaculty();
                TUniver *pUn;
                do {
                    sayToEnterUnivName();
                    cin>>univName;
                 pUn = (TUniver*)univer.getUniv(univName,success);
                 if(!success) {sayNoSuchUniver();}
                }while (!success);
                sayToEnterFacName();
                cin>>facName;
                sayToEnterFacFiodean();
               cin>>pnew->fiodec;
                sayToEnterFacTel();
                cin>>pnew->telnumber;
                pnew->name = facName;
                univer.addFaculty(pnew,pUn,facName);
             
        }   
         else if (choice==5) {
                if (!created) {
                   sayCreateList();
                   goto startPoint;
                }
                bool unIsExist = false;
                bool facOk = false;
                bool tryAg = false;
                string univName;
                string command;
                TUniver* tmpUn;
                do {
                    sayToEnterUnivName();
                    cin>>univName;
                   tmpUn =(TUniver*)(univer.getUniv(univName,unIsExist));
                   facOk = tmpUn->subInit;
                   if (!unIsExist) { sayNoSuchUniver();
                   tryAg = true;}
                   if (!facOk) {sayFacArentInit(); 
                    tryAg = true;}
                   if (tryAg) {
                   askTryAgain();
                   cin>>command;
                   if (command=="try") { }
                   else {
                       goto startPoint;
                   }}
                   
                }while ((!unIsExist)&&(!facOk));
                TFaculty* facTmp;
                int count = tmpUn->sublev->getCount();
                sayFacultiesForUn(univName);
               for (int i=0;i<count;i++) {
                   facTmp =(TFaculty*)tmpUn->sublev->getElem(i);
                   cout<<facTmp->name<<NXLN;
                   cout<<facTmp->fiodec<<NXLN;
                   cout<<facTmp->telnumber<<NXLN;
                   showDots();
               }
                
        } else if (choice==6) {
                if (!created) {
                   sayCreateList();
                    goto startPoint;
                }
               string univName;
                string facName;
                string chairName;
                bool univEx = false;
                bool facEx =false;
                
                TChair *pnew = new TChair();
                TUniver *pUn;
                TFaculty *pFc;
                do {
                    sayToEnterUnivName();
                    cin>>univName;
                 pUn = (TUniver*)univer.getUniv(univName,univEx);
                 if(!univEx) {sayNoSuchUniver();
                 continue;}
                 sayToEnterFacName();
                 cin>>facName;
                 pFc =(TFaculty*)(pUn->sublev->getElem(pUn->sublev->findElList(facName,cmpFact,facEx)));
                 if (!facEx) {sayNoSuchFaculty();
                 continue;}
                }while ((!univEx)&& (!facEx));
                sayToEnterChrName();
                cin>>chairName;
                sayToEnterChrFioZav();
                cin>>pnew->fiozavkaf;
                sayToEnterChrTel();
                cin>>pnew->telnumber;
                pnew->name = chairName;
                univer.addChair(pFc,pnew,chairName);
        } else if (choice==7) {
            if (!created) {
                   sayCreateList();
                   goto startPoint;
                }
             bool unIsExist = false;
             bool facIsExist = false;
             bool chrOk = false;
                bool facOk = false;
                bool tryAg = false;
                string univName;
                string facName;
                string command;
                TUniver* tmpUn;
                TFaculty* tmpFac;
                do {
                    if (tryAg) {
                   askTryAgain();
                   cin>>command;
                   if (command=="try") { }
                   else {
                       goto startPoint;
                   } tryAg = false;
                    }
                    sayToEnterUnivName();
                    cin>>univName;
                   tmpUn =(TUniver*)(univer.getUniv(univName,unIsExist));
                   facOk = tmpUn->subInit;
                   if (!unIsExist) { sayNoSuchUniver();
                   tryAg = true;
                   continue;}
                   if (!facOk) {sayFacArentInit(); 
                    tryAg = true;
                   continue;}
                   sayToEnterFacName();
                   cin>>facName;
                   tmpFac = (TFaculty*)(univer.getFaculty(tmpUn,facName,facIsExist));
                   if (!facIsExist) {
                       sayNoSuchFaculty();
                       tryAg = true;
                       continue;
                   }
                   facOk =tmpFac->subInit;
                   if(!facOk) {
                       sayChairsArentInit();
                       tryAg = true;
                       continue;
                   }
                   
                }while ((!unIsExist)&&(!facOk)&&(facIsExist)&&(facOk));
                TChair* chrTmp;
                int count = tmpFac->sublev->getCount();
                sayChairsForFac(facName);
               for (int i=0;i<count;i++) {
                   chrTmp =(TChair*)tmpFac->sublev->getElem(i);
                   cout<<chrTmp->name<<NXLN;
                   cout<<chrTmp->fiozavkaf<<NXLN;
                   cout<<chrTmp->telnumber<<NXLN;
                   showDots();
               }
               
        } else if (choice==8) {
                if (!created) {
                   sayCreateList();
                   goto startPoint;
                }
              bool unIsExist = false;
             bool facIsExist = false;
             bool chrOk = false;
                bool facOk = false;
                bool tryAg = false;
                bool chIsExist = false;
                string univName;
                string facName;
                string chrName;
                string command;
                int delPos = 0;
                TUniver* tmpUn;
                TFaculty* tmpFac;
                do {
                    if (tryAg) {
                   askTryAgain();
                   cin>>command;
                   if (command=="try") { }
                   else {
                       goto startPoint;
                   } tryAg = false;
                    }
                    sayToEnterUnivName();
                    cin>>univName;
                   tmpUn =(TUniver*)(univer.getUniv(univName,unIsExist));
                   facOk = tmpUn->subInit;
                   if (!unIsExist) { sayNoSuchUniver();
                   tryAg = true;
                   continue;}
                   if (!facOk) {sayFacArentInit(); 
                    tryAg = true;
                   continue;}
                   sayToEnterFacName();
                   cin>>facName;
                   tmpFac = (TFaculty*)(univer.getFaculty(tmpUn,facName,facIsExist));
                   if (!facIsExist) {
                       sayNoSuchFaculty();
                       tryAg = true;
                       continue;
                   }
                   facOk =tmpFac->subInit;
                   if(!facOk) {
                       sayChairsArentInit();
                       tryAg = true;
                       continue;
                   }
                   sayToEnterChrName();
                   cin>>chrName;
                   delPos = (tmpFac->sublev->findElList(chrName,cmpChr,chIsExist));
                   if (!chIsExist) {
                       sayNoSuchChair();
                       tryAg = true;
                       continue;
                   }
                   
                }while ((!unIsExist)&&(!facOk)&&(facIsExist)&&(facOk)&&(chIsExist));
                univer.delChair(tmpFac,delPos);
                showLine();
        } else if (choice==9) {
               bool unIsExist = false;
               bool faExist = false;
               bool facOk = false;
                bool tryAg = false;
                string univName;
                string facName;
                string command;
                TUniver* tmpUn;
                do {
                    if (tryAg) {
                   askTryAgain();
                   cin>>command;
                   if (command=="try") { }
                   else {
                       goto startPoint;
                   } tryAg = false;
                    }
                    sayToEnterUnivName();
                    cin>>univName;
                   tmpUn =(TUniver*)(univer.getUniv(univName,unIsExist));
                   facOk = tmpUn->subInit;
                   if (!unIsExist) { sayNoSuchUniver();
                   tryAg = true;
                   continue;}
                   if (!facOk) {sayFacArentInit(); 
                    tryAg = true;
                   continue;}
                   sayToEnterFacName();
                   cin>>facName;
                   faExist = univer.delFaculty(tmpUn,facName);
                   if (!faExist) {
                       sayNoSuchFaculty();
                       tryAg = true;
                       continue;
                   }
                  
                }while ((!unIsExist)&&(!facOk)&&(faExist));
                showLine();
        } else if (choice==10) {
            if (!created) {
                   sayCreateList();
                   goto startPoint;
                }
            bool unIsExist = false;
               bool facOk = false;
                bool tryAg = false;
                string univName;
                string command;
                TUniver* tmpUn;
                do {
                    if (tryAg) {
                   askTryAgain();
                   cin>>command;
                   if (command=="try") { }
                   else {
                       goto startPoint;
                   } tryAg = false;
                    }
                    sayToEnterUnivName();
                    cin>>univName;
                   tmpUn =(TUniver*)(univer.getUniv(univName,unIsExist));
                   facOk = tmpUn->subInit;
                   if (!unIsExist) { sayNoSuchUniver();
                   tryAg = true;
                   continue;}
                   if (!facOk) {sayFacArentInit(); 
                    tryAg = true;
                   continue;}
                   univer.delAllFaculties(tmpUn,true);
                  
                }while ((!unIsExist)&&(!facOk));
                showLine();
                
    }
         else if (choice==11) {
            if (!created) {
                   sayCreateList();
                   goto startPoint;
                }
            bool unIsExist = false;
                bool tryAg = false;
                string univName;
                string command;
                do {
                    if (tryAg) {
                   askTryAgain();
                   cin>>command;
                   if (command=="try") { }
                   else {
                       goto startPoint;
                   } tryAg = false;
                    }
                    sayToEnterUnivName();
                    cin>>univName;
                    unIsExist = univer.delUniv(univName);
                   if (!unIsExist) { sayNoSuchUniver();
                   tryAg = true;
                   continue;}
                
                }while (!unIsExist);
                showLine();
                
    }
        else if (choice==12) {
            if (!created) {
                   sayCreateList();
                   goto startPoint;
                }
            bool delP = true;
            askDelPointers();
            // take answer 
            univer.delAllUniver(delP);
        }
    }
        return 0;
}
 
