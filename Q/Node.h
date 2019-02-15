class Node {
 public:
  int getData() {
    return m_data;
  }

  Node *getNext() {
    return m_next;
  }

  void setData(int data) {
    m_data = data;
  }

  void setNext(Node *next) {
    m_next = next;
  }

private:
  int m_data;
  Node *m_next;
};
