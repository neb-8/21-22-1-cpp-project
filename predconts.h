#ifndef __PREDCONTS_H_
#define __PREDCONTS_H_
#include <iostream>
#include <cctype>
#include <deque>
#include <deque>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <iterator>

template<typename contType, typename functor, typename Type = typename contType::value_type>
class predicate_containers{
private:
    contType& trueCont;
    contType& falseCont;
    functor dontes;
public:

    predicate_containers(contType& cont1_,contType& cont2_,functor dontes_):
        trueCont(cont1_),
        falseCont(cont2_),
        dontes(dontes_)
        {
            trueCont.resize(0);
            falseCont.resize(0);
        };

    predicate_containers(contType& cont1_,contType& cont2_):
        trueCont(cont1_),
        falseCont(cont2_)
        {
            trueCont.resize(0);
            falseCont.resize(0);
        };


    predicate_containers& insert(Type x){
        if(dontes(x)){
            trueCont.resize(trueCont.size());
            trueCont.push_back(x);
        }
        else{
            falseCont.resize(falseCont.size());
            falseCont.push_back(x);
        }
        return *this;
    }

    
    predicate_containers& insert(std::string::iterator x, std::string::iterator y){
        for(;x!=y;++x){
            this->insert(*x);
        }
        return *this;
    }
    

    predicate_containers& insert(Type *x, Type *y){
        for(;x!=y;++x){
            this->insert(*x);
        }
        return *this;
    }


    predicate_containers& erase(Type x){
        if(dontes(x)){
            contType tmp = trueCont;
            trueCont.resize(0);
            for(typename contType::iterator j=tmp.begin();j!=tmp.end();std::advance(j,1)){
                if(*j!=x){
                    trueCont.resize(trueCont.size());
                    trueCont.push_back(*j);
                }
            }
        }
        else{
            
            contType tmp = falseCont;
            falseCont.resize(0);
            for(typename contType::iterator j=tmp.begin();j!=tmp.end();std::advance(j,1)){
                if(*j!=x){
                    falseCont.resize(falseCont.size());
                    falseCont.push_back(*j);
                }
            }
        }
        return *this;
    }

    long unsigned int size(){
        return ((long unsigned int)trueCont.size() + (long unsigned int)falseCont.size());
    }
};

#endif