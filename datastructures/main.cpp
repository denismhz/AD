#include "../sort/include/person.h"
#include "doublyLinkedList.h"
#include "singlyLinkedList.h"
#include "stack.h"
#include <algorithm>
#include <iostream>
#include <string>

/*
 * gcc -Iincludepath
 */

int isPalyndrome(string);


int main(void) { return 0; }

int isPalyndrome(string s) {
  Stack<char> stack;
  std::transform(s.begin(), s.end(), s.begin(), ::tolower);
  int i = 0;
  int l = 0;
  for (i = 0; s[i] != '\0'; i++) {
    l++;
    if (s[i] >= 'a' && s[i] <= 'z')
      stack.push(s[i]);
  }
  for (int j = 0; j < l; j++) {
    if (s[j] >= 'a' && s[j] <= 'z')
      if (stack.pop() != s[j])
        return 0;
  }
  return 1;
}
