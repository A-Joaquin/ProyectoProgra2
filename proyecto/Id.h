template <class T>
class Id {
private:
    static int id;
public:
    static int getId() {
        return id++;
    }
    static int disminuirId() {
        return id--;
    }
    static void setId(int newId) {
        id = newId;
    }
};

template<typename T>
int Id<T>::id = 0;
