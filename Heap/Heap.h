const int ARRAY_SIZE = 512;

class Heap {
 public:
  Heap() {
    for(int i = 0; i < ARRAY_SIZE; i++) {
      m_data[i] = 0;
    }
  }
  int getLeft(int index) {
    return 2*index + 1;
  }
  int getRight(int index) {
    return 2*index + 2;
  }
  int getParent(int index) {
    return (index-1)/2;
  }
  void insert(int value) {
    m_data[m_last] = value;
    int parentIndex = getParent(m_last);
    int childIndex = m_last;
    while(m_data[parentIndex] > m_data[childIndex] && childIndex != 0) {
      int temp = m_data[parentIndex];
      m_data[parentIndex] = m_data[childIndex];
      m_data[childIndex] = temp;
      childIndex = parentIndex;
      parentIndex = getParent(parentIndex);
    }
    m_last++;
  }
  int delete() {
    m_last--;
    m_data[0] = m_data[m_last];

    int index, leftIndex, rightIndex, smallerIndex;

    index = 0;
    
    while(true) {
      leftIndex = getLeft(index);
      rightIndex = getRight(index);
      
      if(m_data[leftIndex] < m_data[rightIndex]) {
	smallerIndex = leftIndex;
      } else {
	smallerIndex = rightIndex;
      }
      
      if(m_data[index] < m_data[smallerIndex]) {
	// swap
	index = smallerIndex;
      } else {
	break;
      }
    }
  }
 private:
  int m_data[ARRAY_SIZE];
  int m_last = 0;
};
