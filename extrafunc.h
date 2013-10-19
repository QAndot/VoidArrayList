

#ifndef EXTRAFUNC_H
#define	EXTRAFUNC_H
#define NXLN ("\n")
#include <string>
#include <iostream>
using namespace std;

using namespace std;
inline void showHelp() {
      cout<<"1. Initialize main array"<<NXLN
          <<"2. Add new university"<<NXLN 
          <<"3. Show Universities"<<NXLN
          <<"4. Add new faculty"<<NXLN
          <<"5. Show Faculties"<<NXLN
          <<"6. Add new Chair"<<NXLN
          <<"7. Show Chairs"<<NXLN
          <<"8. Delete Chair"<<NXLN
          <<"9. Delete Faculty"<<NXLN 
          <<"10. Delete All Faculties"<<NXLN
          <<"11. Del University"<<NXLN
          <<"12. Del All Universities"<<NXLN;
}
inline void  showWelcome() {
    cout<<"HELLO , WELCOME TO PROGRAMM - Multilist of Universities"<<NXLN;
    cout<<"With the help of this prog you can store and operate with information in dynamic memory"<<NXLN;
}
inline void sayWrongInput() {
    cout<<"You have entered wrong value,try again"<<NXLN;
}
inline void showQuestion () {
    cout<<"What is your choice ? "<<NXLN;
}
inline void askSize() {
    cout<<"What size of list do you need ? "<<NXLN;
}
inline void askAge () {
    cout<<"Please enter age"<<NXLN;
}
inline void askName() {
    cout<<"Please enter name"<<NXLN;
}
inline void sayInvalidRaplace() {
    cout<<"You have entered nonexistent element name.Try again"<<NXLN;
}
inline void askElToDel() {
    cout<<"Please enter name of element which you want to delete"<<NXLN;
}
inline void askDelPoint() {
    cout<<"Do you want to delete pointer array ? Type yes to delete. No - to leave in memory"<<NXLN;
}
inline void sayCreateList() {
   
    cout<<"At first please create list"<<NXLN;
}
inline void askElToReplace() {
     cout<<"Please enter the name of the element you want to replace"<<NXLN;
 }
inline void showLine() {
    cout<<"_______________________________________________"<<NXLN; }
inline void sayAlreadyExist() {
    cout<<"List is already exist in memory"<<NXLN;
}
inline void sayToDel() {
    cout<<"Please delete all list ,before initializing new , or you will clog memory"<<NXLN;
}
inline void sayToEnterUnivName() {
    cout<<"Please enter university name"<<NXLN;
}
inline void sayToEnterUnivFiorec() {
    cout<<"Please enter FIO of rector"<<NXLN;
}
inline void sayToEnterUnivTel() {
    cout<<"Please enter phone number of univerity"<<NXLN;
}
inline void sayToEnterFacName() {
    cout<<"Please enter faculty name"<<NXLN;
}
inline void sayToEnterFacFiodean() {
    cout<<"Please enter FIO of dean"<<NXLN;
}
inline void sayToEnterFacTel() {
    cout<<"Please enter phone number of dean's office"<<NXLN;
}
inline void sayNoSuchUniver() {
    cout<<"No such university has been found,please try again"<<NXLN;
}
inline void sayFacArentInit() {
    cout<<"This university doesn't has initialized faculties."<<NXLN;
}
inline void sayChairsArentInit() {
    cout<<"This faculty doesn't has initialized chairs."<<NXLN;
}
inline void askTryAgain () {
    cout<<"Do you want to try again (type 'try') or choose another command  (type anything)"<<NXLN;
}
inline void sayFacultiesForUn(string name) {
    cout<<"Faculties for University - "<<name<<" are :"<<NXLN;
}
inline void sayChairsForFac(string name) {
    cout<<"Faculties for Faculty - "<<name<<" are :"<<NXLN;
}
inline void showDots() {
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<NXLN;
}
inline void askDelPointers() {
cout<<"Do you want to delete pointer array ?"<<NXLN;
}
inline void sayNoSuchFaculty() {
    cout<<"No such faculty has been found in this university,please try again"<<NXLN;
}
inline void sayNoSuchChair() {
    cout<<"No such faculty has been found in this university,please try again"<<NXLN;
}
inline void sayToEnterChrName() {
    cout<<"Please enter chair name"<<NXLN;
}
inline void sayToEnterChrFioZav() {
    cout<<"Please enter FIO of zav chair"<<NXLN;
}
inline void sayToEnterChrTel() {
    cout<<"Please enter phone number of dean's office"<<NXLN;
}

#endif	/* EXTRAFUNC_H */

