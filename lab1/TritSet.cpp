#include "TritSet.h"
#include <iostream>
#include <math.h>

TritSet::TritSet(size_t size):size_((size_t)(ceil((double)(size)*2 / 8 / sizeof(int)))),
                              trits(new int [size_]),
                              size_orig_(size),
                              index_size_(size){
    int num = emply_cell();
    for(int i = 0; i < size_; i++)
        trits[i] = num;
}

size_t TritSet::capacity(){
    return size_;
}

size_t TritSet::length(){
    return logical_length_;
}

TritSet::TritSet() : size_(0), trits(new int [0]),size_orig_(0), index_size_(0){

}

int TritSet::emply_cell(){
    int num = 0;
    for(int i = 0; i < 16; i++,num++)
        num<<=2;
    return num;
}


TritSet::TritSet( TritSet const &a):size_(a.size_),
                                    trits(new int32_t[size_]),
                                    size_orig_(a.size_orig_),
                                    index_size_(a.index_size_),
                                    logical_length_(a.logical_length_){
    for(int i = 0; i < size_; i++)
        trits[i] = a.trits[i];
}

TritSet & TritSet::operator=(TritSet const & a)
{
    if(this != &a) {
        delete [] trits;
        new (this) TritSet(a);
    }
    return *this;
}



TritSet::~TritSet(){
    delete[] this->trits;

}

void TritSet::resize(size_t size){
    size_t size_arr= (int)(ceil(static_cast<double>(size)*2 / 8 / sizeof(int)));
    auto *arr = new int32_t[size_arr];

    memcpy( (void*)arr, (void*)trits, size_arr*sizeof(int));

    size_ = (size_t)(ceil(double(size)*2 / 8 / sizeof(int)));
    delete [] trits;
    trits = arr;
    setLength();
}

Trit TritSet::getTrit(size_t index = 0) const
{
    size_t rem = index%16*2;
    size_t div = index/16;
    if(div >= size_)
        return Unknown;
    int trit = ((trits[div])>>rem)&3;
    return convert(trit);

}

Trit TritSet::Reference::getTrit() const{
    return this->tritset[pos];
}

void TritSet::trim(size_t lastIndex){
    if(lastIndex>=logical_length_)
        return;
    for(int i = logical_length_; i >= lastIndex;i--)
        setTrit(Unknown,i);
    this->resize(lastIndex);


}
void TritSet::setLength(){
    for(int i = this->logical_length_;i;i--)
        if(this->getTrit(i-1) == Unknown)
            this->logical_length_--;
        else
            break;

}

void TritSet::setLength(size_t index){
    for(size_t i = index;i;i--)
        if(this->getTrit(i) == Unknown)
            this->logical_length_ = i;
        else
            break;

}

void TritSet::shrink(){

    resize(std::max(last_set,(int)size_orig_));
}

size_t TritSet::cardinality(Trit value){
    size_t counter = 0;
    for(size_t i = 0; i < logical_length_; i++){
        if (getTrit(i) == value)
            counter++;
    }
    return counter;
}

std::unordered_map< Trit, int, std::hash<int> > TritSet::cardinality(){
    int counterT = 0,counterF=0,counterU=0;
    for(size_t i = 0; i < logical_length_; i++){
        switch (getTrit(i)) {
            case True:
                counterT++;
                break;
            case False:
                counterF++;
                break;
            case Unknown:
                counterU++;
                break;
        }
    }

    std::unordered_map<Trit, int, std::hash<int> > map{{True,counterT},
                                                       {False,counterF},
                                                       {Unknown,counterU}};
    return map;
}


int TritSet::setTrit(Trit trit, size_t index = 0){



    size_t rem = index%16*2;
    size_t div = index/16;
    if (div >= size_) {
        if (trit == Unknown) {

            return 0;
        }
        else
            this->resize(index+1);
    }
    if(trit == Unknown)
        this->setLength();
    if(index>=logical_length_)
        logical_length_ = index + 1;

    trits[div] = (trits[div] & (~(3<<rem))) | (convert(trit)<<rem);
    if(trit != Unknown)
        last_set=index;
    return 0;
}

Trit TritSet::convert(int num){
    return num == 0?False:num == 1?Unknown:True;
}
int TritSet::convert(Trit trit){
    return trit == False?0:trit==True?3:1;
}



TritSet::Reference::Reference(TritSet & tritset, size_t pos):tritset(tritset), pos(pos)
{



}


TritSet::Reference & TritSet::Reference::operator=(Trit t){
    tritset.setTrit(t,pos);

    return *this;

}

TritSet::Reference & TritSet::Reference::operator=(Reference const& ref){
    tritset.setTrit(ref.tritset[ref.pos],pos);
    return *this;
}



TritSet::Reference TritSet::operator[](size_t pos){


    return Reference( *this,pos);

}

Trit TritSet::operator[](size_t size) const{
    return getTrit((int)size);
}

TritSet::Reference::operator Trit() const{
    return tritset.getTrit(pos);

}


TritSet::Reference::~Reference(){


}

TritSet operator&(TritSet const & a, TritSet const & b){
    TritSet res(a.size_>b.size_?a.size_*16:b.size_*16);
    size_t length = std::max(a.logical_length_,b.logical_length_);
    for(int i = 0; i < length; i++){
        Trit a_buf = a[i];
        Trit b_buf = b[i];
        int a_num = a.convert(a_buf);
        int b_num = b.convert(b_buf);
        int res_buf = a_num&b_num;
        res[i] = a.convert(res_buf);
    }


    return res;

}
TritSet operator|(TritSet const & a, TritSet const & b){
    TritSet res(a.size_>b.size_?a.size_:b.size_);
    size_t length = std::max(a.logical_length_,b.logical_length_);
    for(int i = 0; i < length; i++) {
        Trit a_buf = a[i];
        Trit b_buf = b[i];
        int a_num = a.convert(a_buf);
        int b_num = b.convert(b_buf);
        int res_buf = a_num|b_num;
        res[i] = a.convert(res_buf);
    }
    return res;
}
TritSet operator~(TritSet const & a){

    TritSet res(a.size_);
    for(int i = 0; i < a.logical_length_; i++){
        switch(a[i]){
            case True:
                res[i] = False;
                break;
            case False:
                res[i] = True;
                break;
            case Unknown:
                res[i] = Unknown;
                break;
        }
    }

    return  res;

}


bool operator==(Trit const & a, TritSet::Reference const & b){
    return a==b.getTrit();
}
bool operator==(TritSet::Reference const & a, Trit const & b){
    return a.getTrit()==b;
}
bool operator==(TritSet::Reference const & a, TritSet::Reference const & b){
    return a.getTrit()==b.getTrit();
}
