#include <iostream> 
using namespace std; 
 
class Node { 
public: 
    string product_name; 
    float price; 
    Node* prev; 
    Node* next; 
}; 
 
class DoublyLinkedList { 
public: 
    Node* head; 
    Node* tail; 
 
    DoublyLinkedList() { 
        head = nullptr; 
        tail = nullptr; 
    } 
 
    void push(string product_name, float price) { 
        Node* newNode = new Node; 
        newNode->product_name = product_name; 
        newNode->price = price; 
        newNode->prev = nullptr; 
        newNode->next = head; 
        if (head != nullptr) { 
            head->prev = newNode; 
        } else { 
            tail = newNode; 
        } 
        head = newNode; 
    } 
    
    void pop() { 
        if (head == nullptr) { 
            return; 
        } 
        Node* temp = head; 
        head = head->next; 
        if (head != nullptr) { 
            head->prev = nullptr; 
        } else { 
            tail = nullptr; 
        } 
        delete temp; 
    } 
    
    bool update(string oldProduct, string newProduct, float newPrice) { 
        Node* current = head; 
        while (current != nullptr) { 
            if (current->product_name == oldProduct) { 
                current->product_name = newProduct; 
                current->price = newPrice; 
                return true; 
            } 
            current = current->next; 
        } 
        return false; 
    } 
    
    void deleteAll() { 
        Node* current = head; 
        while (current != nullptr) { 
            Node* temp = current; 
            current = current->next; 
            delete temp; 
        } 
        head = nullptr; 
        tail = nullptr; 
    } 
    
    void display() { 
        Node* current = head; 
        while (current != nullptr) { 
            cout << current->product_name << " (Rp" << current->price << ")" << endl; 
            current = current->next; 
        } 
    } 
    
    void insert(string product_name, float price, int position) { 
        if (position <= 0) { 
            push(product_name, price); 
            return; 
        } 
        Node* current = head; 
        for (int i = 1; i < position && current != nullptr; i++) { 
            current = current->next; 
        } 
        if (current == nullptr) { 
            Node* newNode = new Node; 
            newNode->product_name = product_name; 
            newNode->price = price; 
            newNode->prev = tail; 
            newNode->next = nullptr; 
            if (tail != nullptr) { 
                tail->next = newNode; 
            } else { 
                head = newNode; 
            } 
            tail = newNode; 
        } else { 
            Node* newNode = new Node; 
            newNode->product_name = product_name; 
            newNode->price = price; 
            newNode->prev = current->prev; 
            newNode->next = current; 
            if (current->prev != nullptr) { 
                current->prev->next = newNode; 
            } else { 
                head = newNode; 
            } 
            current->prev = newNode; 
        } 
    } 
    
    void remove(int position) { 
        if (position <= 0) { 
            pop(); 
            return; 
        } 
        Node* current = head; 
        for (int i = 1; i < position && current != nullptr; i++) { 
            current = current->next; 
        } 
        if (current == nullptr) { 
            return; 
        } 
        if (current == head) { 
            head = current->next; 
        } else { 
            current->prev->next = current->next; 
        } 
        if (current == tail) { 
            tail = current->prev; 
        } else { 
            current->next->prev = current->prev; 
        } 
        delete current; 
    } 
}; 

int main() { 
    DoublyLinkedList list; 
    int choice; 
    string productName, newProductName; 
    float price, newPrice; 
    int position; 
    do { 
        cout << "1. tambah data\n"; 
        cout << "2. hapus data\n"; 
        cout << "3. Update data \n"; 
        cout << "4. tambah data urutan tertentu insert\n"; 
        cout << "5. hapus data urutan tertentu remove\n"; 
        cout << "6. hapus seluruh data\n"; 
        cout << "7. tampilkan data\n"; 
        cout << "8. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
        switch (choice) { 
            case 1: 
                cout << "masukan nama produk: "; 
                cin >> productName; 
                cout << "masukan harga: "; 
                cin >> price; 
                list.push(productName, price); 
                break; 
            case 2: 
                list.pop(); 
                break; 
            case 3: 
                cout << "masukan nama produk yang lama: "; 
                cin >> productName; 
                cout << "masukan nama produk yang baru: "; 
                cin >> newProductName; 
                cout << "masukan harga baru: "; 
                cin >> newPrice; 
                if (list.update(productName, newProductName, newPrice)) { 
                    cout << "Produk berhasil ditambahkan\n"; 
                } else { 
                    cout << "produk tidak ada\n"; 
                } 
                break; 
            case 4: 
                cout << "masukan nama produk: "; 
                cin >> productName; 
                cout << "masukan harga: "; 
                cin >> price; 
                cout << "masukan posisi: "; 
                cin >> position; 
                list.insert(productName, price, position); 
                break; 
            case 5: 
                cout << "masukan urutan ke-: "; 
                cin >> position; 
                list.remove(position); 
                break; 
            case 6: 
                list.deleteAll(); 
                cout << "semua produk berhasil di hapus\n"; 
                break; 
            case 7: 
                list.display(); 
                break; 
            case 8: 
                cout << "keluar dari progam...\n"; 
                break; 
            default: 
                cout << "pilihan salah\n"; 
                break; 
        } 
    } while (choice != 8); 
 
    return 0; 
} 
