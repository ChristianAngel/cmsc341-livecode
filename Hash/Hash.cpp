#include <iostream>
using namespace std;
const int CAPACITY = 10;

class Hash {
public:
  Hash() {
    for(int i = 0; i < CAPACITY; i++) {
      m_array[i] = 0;
    }
  }

  void print() {
    for(int i = 0; i < CAPACITY; i++) {
      cout << m_array[i] << endl;
    }
  }
long long hash(int a) {
    return (64732189463291 * a + 7410238907) % 2147382910473817;
  }
  void insert(int a) {
    long long myHash = hash(a);
    m_array[myHash % CAPACITY] = a;
  }
  void del(int a) { }
private:
  int m_array[CAPACITY];
};

int main() {
  Hash myHashTable;
  myHashTable.print();
  myHashTable.insert(5);
  myHashTable.print();  
}
