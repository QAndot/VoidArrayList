#include "cmpFunc.h"

int cmpUniv(void*p, string key){
    if (((TUniver*)p)->name == key)
    {
        return 0;
    }
    else {
        if (((TUniver*)p)->name > key)
           {
            return 1;
        }
        else {return -1;}
    }
}
int cmpFact(void *p, string key){
    if (((TFaculty*)p)->name == key)
    {
        return 0;
    }
    else { if (((TFaculty*)p)->name > key)
           {
            return 1;
        }
        else {return -1;}
    }
}
int cmpChr(void *p, string key){
    if (((TChair*)p)->name == key)
    {
        return 0;
    }
    else { if (((TChair*)p)->name > key)
           {
            return 1;
        }
        else {
            return -1;
        }
    }
}

