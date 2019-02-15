#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
  Queue myQueue;
  
  myQueue.enqueue(0);
  cout << "Enqueued the first one" << endl;
  myQueue.enqueue(1);
  myQueue.enqueue(2);
  myQueue.enqueue(3);
  myQueue.enqueue(4);

  cout << "Done enqueueing" << endl;

  for(Queue::QueueIterator it = myQueue.qBegin(); it != myQueue.qEnd(); it++) {
    cout << *it << endl;
  }

  //for(int i = 0; i < 6; i++)
  // cout << myQueue.dequeue() << endl;
  
  /*  myList.print();
  cout << myList.deleteAt(2) << endl;
  myList.print();
  cout << myList.deleteAt(1) << endl;
  myList.print();
  cout << myList.deleteAt(2) << endl;
  myList.print();*/
  return 0;
}
