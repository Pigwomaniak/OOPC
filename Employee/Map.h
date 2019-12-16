#pragma once
#include <iostream>
using namespace std;

template <class kType,class eType>

class Map {
    class Cell{
    public:
        Cell* next;
        kType key;
        eType* element;
        Cell(kType newKey, eType* newElementPtr){
            next = nullptr;
            key = newKey;
            element = newElementPtr;
        }
        ~Cell(){
            delete element;
        }
    };

private:
    Cell* last;
    Cell* first;
    bool checkKeyExist(const kType& key) const{
        Cell* current = first;
        while (current){
            if(current->key == key){
                return true;
            }
            current = current->next;
        }
        return false;
    }
public:
    Map(){
        last = nullptr;
        first = nullptr;
        //current = nullptr;
    }
    Map(const Map& src){
        last = nullptr;
        first = nullptr;
        Cell* current = src.first;
        while (current){
            add(current->key, *current->element);
            current = current->next;
        }
    }

    ~Map(){
        Cell* current = first;
        Cell* temp;
        while (current){
            temp = current->next;
            delete current;
            current = temp;
        }
    }

    void add(const kType& key, const eType element){
        if(checkKeyExist(key)){
            //cout << "KEY exist\n";
            return;
        }
        if(last){
            last->next = new Cell(key, new eType(element));
            last = last->next;
        } else{
            last = new Cell(key, new eType(element));
            first = last;
        }
    }

    eType* find(const kType& key) const{
        Cell* current = first;
        while (current){
            if(current->key == key){
                return current->element;
            }
            current = current->next;
        }
        return nullptr;
    }

    friend ostream&operator << (ostream& out, const Map& src){
        Cell* current= src.first;
        while (current){
            out << current->key << "\n" << *current->element << endl;
            current = current->next;
        }
        return out;
    }

    Map& operator = (const Map& src){
        Cell* current = first;
        Cell* temp;
        while (current){
            temp = current->next;
            delete current;
            current = temp;
        }
        first = nullptr;
        last = nullptr;
        current = src.first;
        while (current){
            add(current->key, *current->element);
            current = current->next;
        }
        return *this;
    }
}
;
