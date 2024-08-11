#include <iostream>

using namespace std;

typedef int object; // OBdA seien die Objekte vom Typ int
class element {
public:
  object val;
  element *next;
};

class list {
private:
  element *head;                   // Zeiger auf Listenanfang
  element *tail;                   // Zeiger auf das Ende
  void deleteList(element *first); // private Loeschfkt.
  element *partition(element *low, element *high);
  void quickSort(element *low, element *high);
  void swap(object &a, object &b);

public:
  list();
  ~list();
  void append(object o);      // Fuegt Wert hinzu
  void deleteList();          // gesamte Liste loeschen
  void deleteValue(object o); // Wert entfernen
  void print();               // Liste // Liste ausgeben
  void quickSort();
};

list::list() {
  head = NULL;
  tail = NULL;
}

void list::deleteList(element *first) {
  if (first != NULL) {
    if (first->next != NULL)
      deleteList(first->next);
    delete first;
  }
}

void list::deleteList() { deleteList(head); }

void list::append(object o) {
  element *elem = new element;
  elem->val = o;
  elem->next = NULL;
  if (tail == NULL) {
    head = elem;
    tail = elem;
  } else {
    tail->next = elem;
    tail = elem;
  }
}

void list::deleteValue(object o) {
  element *curr = head, *prev = NULL;
  while (curr != NULL) {
    if (curr->val == o) {
      if (prev == NULL)
        head = curr->next;
      else
        prev->next = curr->next;
      if (curr == tail)
        tail = prev;
      element *h = curr;
      curr = curr->next;
      delete h;
    } else {
      prev = curr;
      curr = curr->next;
    }
  }
}

void list::print() {
  element *curr = head;
  while (curr != NULL) {
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;
}

list::~list() {
  deleteList(head);
  head = NULL;
  tail = NULL;
}

void list::swap(object &a, object &b) {
  object temp = a;
  a = b;
  b = temp;
}

// Partition the linked list around a pivot element
/*element *list::partition(element *low, element *high) {
  object pivot = high->val;
  element *pivotP = high;
  element *i = low;

  element *gte = NULL;
  element *lt = NULL;

  // imagin we got two lists, append to greather than list everything that is
  // greater than pivot append to less than list everything that is smaller than
  // pivot, then merge the lists(append to tail of less than list pivot) append
  // to pivot->greater than list
  // set the new tail to end of greater than list

  for (element *j = low; j != high; j = j->next) {
    if (j->val < pivotP->val) {
      lt->next = j;
      lt = lt->next;
    } else if (j->val >= pivotP->val) {
      if (gte == NULL) {
      }
      gte->next = j;
      gte = gte->next;
    }
  }
  // append all the lists
  lt->next = pivotP;
  return pivotP;
}*/

element *list::partition(element *low, element *high) {
  element *pivotP = low;
  element *curr = low->next;
  element *prev = low;

  while (curr != tail->next) {
    if (pivotP->val > curr->val) {
      swap(prev->next->val, curr->val);
      prev = prev->next;
    }
    curr = curr->next;
  }
  swap(prev->val, pivotP->val);
  return prev;
}

// Implement QuickSort on the linked list
void list::quickSort(element *low, element *high) {
  if (low != NULL && high != NULL && low != high && low != high->next) {
    element *pivot = partition(low, high);
    quickSort(low, pivot);
    quickSort(pivot->next, high);
  }
}

// Wrapper function for QuickSort
void list::quickSort() { quickSort(head, tail); }

int main() {
  list myList;
  myList.append(5);
  myList.append(2);
  myList.append(8);
  myList.append(1);
  myList.append(9);

  cout << "Original list: ";
  myList.print();

  myList.quickSort();

  cout << "Sorted list: ";
  myList.print();

  return 0;
}
