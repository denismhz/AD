#include <iostream>

template <class T> class binSearchTree {
  typedef struct _treeElement {
    T data;
    struct _treeElement *left;
    struct _treeElement *right;
  } treeElement;

private:
  treeElement *root; // Wurzel des Baums
  void insert(treeElement *currRoot, treeElement *elem);
  void deleteTree(treeElement *root);
  void print(treeElement *root);
  treeElement *findSuccessor(treeElement *);

public:
  binSearchTree();
  ~binSearchTree();
  void insert(T);      // Wert einfuegen
  bool contains(T);    // Wert enthalten
  void deleteValue(T); // Wert loeschen
  void print();
};

template <typename T> binSearchTree<T>::binSearchTree() { this->root = NULL; }

template <typename T> void binSearchTree<T>::deleteTree(treeElement *root) {
  if (root != NULL) {
    if (root->left != NULL)
      deleteTree(root->left);
    if (root->right != NULL)
      deleteTree(root->right);
    delete root;
  }
  // Laufzeit Theta(n) einmal wird jeder knoten durchlaufen
}

template <typename T> binSearchTree<T>::~binSearchTree() {
  deleteTree(root);
  root = NULL;
}

template <typename T> bool binSearchTree<T>::contains(T val) {
  treeElement *curr = root;
  while (curr != NULL) {
    if (curr->data == val)
      return true;
    else {
      if (val <= curr->data)
        curr = curr->left;
      else
        curr = curr->right;
    }
  }
  return false;
  // Laufzeit BC Theta(1), WC Theta(n), AC Theta(log n)
}

template <typename T> void binSearchTree<T>::insert(T val) {
  treeElement *newElem = new treeElement;
  newElem->data = val;
  newElem->left = NULL;
  newElem->right = NULL;
  if (root == NULL)
    root = newElem;
  else
    insert(root, newElem);
  // Laufzeit BC Theta(1), WC Theta(n), AC Theta(log n)
}

template <typename T>
void binSearchTree<T>::insert(treeElement *currRoot, treeElement *elem) {
  if (elem->data <= currRoot->data) {
    if (currRoot->left == NULL)
      currRoot->left = elem;
    else
      insert(currRoot->left, elem);
  } else {
    if (currRoot->right == NULL)
      currRoot->right = elem;
    else
      insert(currRoot->right, elem);
  }
  // Laufzeit BC Theta(1), WC Theta(n), AC Theta(log n)
}

template <typename T> void binSearchTree<T>::print() {
  print(root);
  std::cout << std::endl;
}

template <typename T> void binSearchTree<T>::print(treeElement *root) {
  if (root != NULL) {
    std::cout << "(";
    print(root->left);                     // left (rek. Aufruf)
    std::cout << "," << root->data << ","; // root ausgeben
    print(root->right);                    // right (rek. Aufruf)
    std::cout << ")";
  } else {
    std::cout << "n";
  }
}

template <typename T> void binSearchTree<T>::deleteValue(T val) {
  treeElement *curr = root;
  treeElement *prev = NULL;

  // Search for the node to delete
  while (curr != NULL && curr->data != val) {
    prev = curr;
    if (val < curr->data)
      curr = curr->left;
    else
      curr = curr->right;
  }

  // If the value is not found
  if (curr == NULL) {
    std::cout << "Value " << val << " not found in the tree." << std::endl;
    return;
  }

  // Case 1: Node to delete is a leaf (no children)
  if (curr->left == NULL && curr->right == NULL) {
    if (prev == NULL) {
      // If the root is the only node in the tree
      delete root;
      root = NULL;
    } else if (prev->left == curr) {
      delete curr;
      prev->left = NULL;
    } else {
      delete curr;
      prev->right = NULL;
    }
  }
  // Case 2: Node to delete has one child
  else if (curr->left == NULL || curr->right == NULL) {
    treeElement *child = (curr->left != NULL) ? curr->left : curr->right;
    if (prev == NULL) {
      // If deleting the root with one child
      delete curr;
      root = child;
    } else if (prev->left == curr) {
      delete curr;
      prev->left = child;
    } else {
      delete curr;
      prev->right = child;
    }
  }
  // Case 3: Node to delete has two children
  else {
    treeElement *successor = findSuccessor(curr->right);
    T successorData = successor->data;
    deleteValue(successorData); // Recursively delete the successor
    curr->data = successorData;
  }
}

// Helper function to find the successor node (smallest node in the right
// subtree)
template <typename T>
typename binSearchTree<T>::treeElement *
binSearchTree<T>::findSuccessor(treeElement *node) {
  while (node->left != NULL) {
    node = node->left;
  }
  return node;
}

int main() {
  binSearchTree<int> myTree;

  // Test Case 1: Insertion
  myTree.insert(50);
  myTree.insert(30);
  myTree.insert(70);
  myTree.insert(20);
  myTree.insert(40);
  myTree.insert(60);
  myTree.insert(80);

  // Test Case 2: Search
  std::cout << "Does the tree contain 40? "
            << (myTree.contains(40) ? "Yes" : "No") << std::endl;
  std::cout << "Does the tree contain 45? "
            << (myTree.contains(45) ? "Yes" : "No") << std::endl;

  // Test Case 3: Deletion
  std::cout << "Tree before deletion: ";
  myTree.print();
  myTree.deleteValue(70);
  std::cout << "Tree after deleting 40: ";
  myTree.print();

  // Test Case 4: Additional Insertions and Deletions
  myTree.insert(10);
  myTree.insert(90);
  std::cout << "Tree after inserting 10 and 90: ";
  myTree.print();

  myTree.deleteValue(60);
  std::cout << "Tree after deleting 60: ";
  myTree.print();

  return 0;
}
