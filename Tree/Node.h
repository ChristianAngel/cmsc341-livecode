class PointerNode {
 public:
  int getData() {
    return m_data;
  }

  void setData(int data) {
    m_data = data;
  }

  void setChild1(PointerNode *node) {
    m_child1 = node;
  }

  void setChild2(PointerNode *node) {
    m_child2 = node;
  }

private:
  int m_data;
  PointerNode *m_child1;
  PointerNode *m_child2;
};

class ArrayNode {
 public:
  ArrayNode() {
    m_children[0] = NULL;
    m_children[1] = NULL;
  }
  
  int getData() {
    return m_data;
  }

  void setData(int data) {
    m_data = data;
  }

  void setChild1(ArrayNode *node) {
    m_child1 = node;
  }

  void setChild2(ArrayNode *node) {
    m_child2 = node;
  }

private:
  int m_data;
  ArrayNode *m_children[2];
};

class TreeNode {
 public:
  TreeNode() {
    m_data = 0;
  }
  
  int getData() {
    return m_data;
  }

  void setData(int data) {
    m_data = data;
  }

  void addChild(TreeNode *node) {
    children.insertEnd(node);
  }

private:
  int m_data;
  LinkedList<TreeNode *> children;
};
