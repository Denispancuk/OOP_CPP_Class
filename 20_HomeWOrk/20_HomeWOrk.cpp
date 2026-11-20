#include <iostream>
using namespace std;
template<typename T>
class List {
    struct Node {
        Node* prev;
        T value;
        Node* next;
        Node() :prev(nullptr), value(0), next(nullptr) {}
        Node(Node* p, T v, Node* n) :prev(p), value(v), next(n) {}

    };
private:
    Node* head;
    Node* tail;
public:
    List()
    {
        head = tail = nullptr;
    }
    bool IsEmpty() {
        return (head == nullptr and tail == nullptr);
    }

    void AddToHead(T value) {
        Node* newNode = new Node(nullptr, value, head);
        if (IsEmpty()) {
            head = tail = newNode;
        }
        else {
            head->prev = newNode;
            head = newNode;
        }
    }
    void DeleteFromHead() {
        if (IsEmpty())
            throw underflow_error("List is empty");
        if (head->next == nullptr)
        {
            delete head;
            head = tail = nullptr;
        }
        else {
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
        }
    }
    void AddToTail(T value)
    {

        Node* newNode = new Node(tail, value, nullptr);
        if (IsEmpty())
        {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }

    }
    void DeleteFromTail() {
        if (IsEmpty())
            throw underflow_error("List is empty");;
        if (head->next == nullptr)
        {
            delete head;
            head = tail = nullptr;
        }
        else {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }

    }
    void AddToPos(int pos, T value) {
        if (pos <= 0) {
            throw invalid_argument("Position less or equal 0");
        }
        if (pos == 1) {
            AddToHead(value);
            return;
        }
        int j = 1;
        for (Node* i = head; i != nullptr; i = i->next)
        {
            if (j == pos)
            {
                Node* newNode = new Node(i->prev, value, i);
                i->prev->next = newNode;
                i->prev = newNode;
                return;
            }
            j++;
        }
        if (j == pos) {
            AddToTail(value);
            return;
        }
        cout << "Not find pos" << endl;

    }
    bool DeleteToPos(int pos) {
        if (pos <= 0) {
            throw invalid_argument("Position less or equal 0");
        }
        if (pos == 1) {
            DeleteFromHead();
            return true;
        }
        int j = 1;

        for (Node* i = head; i != nullptr; i = i->next)
        {
            if (j == pos)
            {
                if (i == tail) {
                    DeleteFromTail();
                    return true;
                }
                i->prev->next = i->next;
                i->next->prev = i->prev;
                delete i;
                return true;
            }
            j++;
        }
        throw invalid_argument("Not find position");
    }
    void Print() {
        for (Node* i = head; i != nullptr; i = i->next)
        {
            cout << i->value;
        }
    }
    ~List() {
        Node* current = nullptr;
        while (head != nullptr)
        {
            current = head;
            head = head->next;
            delete current;
        }
    }
};

class Train {
public:
    struct Vagon {
        int NumberVagon;
        int CountOfPlaces;
        int CountOfPassanger;
        friend ostream& operator << (ostream& out, const Vagon& vagon)
        {
            out << "Number Vagon: " << vagon.NumberVagon << "\nCount Of Places: " << vagon.CountOfPlaces << "\nCount Of Passanger: " << vagon.CountOfPassanger << endl << endl;
            return out;
        }
    };
private:
    string model;
    List<Vagon> vagons;
    int countVagons;
public:
    Train() :model("None"), countVagons(0) {}
    Train(string model, int countVagons = 0) :model(model), countVagons(countVagons) {}
    void Show() {
        vagons.Print();
    }
    void AddVagonToHead(const Vagon& vagon) {
        vagons.AddToHead(vagon);
        countVagons++;
    }
    void AddVagonToTail(const Vagon& vagon) {
        vagons.AddToTail(vagon);
        countVagons++;
    }
    void DeleteVagonToTail() {
        vagons.DeleteFromTail();
        if (countVagons > 0) countVagons--;
        else {
            throw invalid_argument("Size already less or equal 0");
        }
    }
    void DeleteVagonToHead() {
        vagons.DeleteFromHead();
        if (countVagons > 0) countVagons--;
        else {
            throw invalid_argument("Size already less or equal 0");
        }
    }
    void DeleteVagonToPos(int pos) {
        if (vagons.DeleteToPos(pos) == true) {
            countVagons--;
        }
        else {
            throw exception("Element not deleted");
        }

    }
    void AddVagonToPos(int pos, const Vagon& vagon) {
        vagons.AddToPos(pos, vagon);
        countVagons++;
    }

};

int main()
{
    try
    {
        Train myTrain("Intercity+");

        Train::Vagon v1 = { 1, 60, 15 };
        Train::Vagon v2 = { 2, 50, 50 };
        Train::Vagon v3 = { 3, 70, 60 };
        Train::Vagon v4 = { 4, 80, 75 };

        myTrain.AddVagonToTail(v1);
        myTrain.AddVagonToHead(v2);

        cout << "First Show" << endl;
        myTrain.Show();


        myTrain.AddVagonToPos(2, v3);

        cout << "After AddVagonToPos:" << endl;
        myTrain.Show();


        myTrain.DeleteVagonToPos(100);

        cout << "After DeleteVagonToPos:" << endl;
        myTrain.Show();
    }
    catch (underflow_error ex)
    {
        cout << ex.what() << endl;
    }
    catch (invalid_argument ex)
    {
        cout << ex.what() << endl;
    }
    catch (exception ex)
    {
        cout << ex.what() << endl;
    }
    catch (...)
    {
        cout << "Unknown error" << endl;
    }
    

}