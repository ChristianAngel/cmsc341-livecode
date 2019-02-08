class Node {
 public:
  int getData() {
    return m_data;
  }

  Node *getNext() {
    return m_next;
  }

  Node *getPrev() {
    return m_prev;
  }

  void setData(int data) {
    m_data = data;
  }

  void setNext(Node *next) {
    m_next = next;
  }

  void setPrev(Node *prev) {
    m_prev = prev;
  }

 private:
  int m_data;
  Node *m_next;
  Node *m_prev;
};
