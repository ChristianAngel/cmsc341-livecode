vector<TreeNode *> TreeNode::cousins() {
  if(m_parent == NULL) {
    // throw an exception
  }
  if(m_parent->m_parent == NULL) {
    // throw an exception
  }
  TreeNode *grandparent = m_parent->m_parent;
  TreeNode *aunt = NULL;
  if(grandparent->m_left == m_parent) {
    aunt = grandparent->m_right;
  }
  if(grandparent->m_right == m_parent) {
    aunt = grandparent->m_left;
  }

  if(aunt == NULL) {
    // throw an exception
  }
  
  vector<TreeNode *> returnValue;
  returnValue.push_back(aunt->m_right);
  returnValue.push_back(aunt->m_left);
  return returnValue;
}
