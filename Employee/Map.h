template <class kType,class eType>

class Map {
    /*
    typedef struct cell {
        cell* next;
        kType key;
        eType* element;
    } cell;
     */
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
            delete key;
            delete element;
        }
    };

private:
    Cell* last;
    Cell* first;
    Cell* current;
public:
    Map(){
        last = nullptr;
        first = nullptr;
        current = nullptr;
    }
    void add(const kType& key, const eType& element){

    }

    eType* find(const kType& key) const{

    }
}
;