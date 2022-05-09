// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include <iostream>
#include "tstack.h"


int operat(char pr) {
    switch (pr) {
    case '(':
      return 0;
    case ')':
      return 1;
    case '+':
      return 2;
    case '-':
      return 2;
    case '*':
      return 3;
    case '/':
      return 3;
    default:
        return -1;
    }
}
int calcul(char k, int x, int y) {
    switch (k) {
    case '+':
        return x + y;
            break;
    case '-':
        return x - y;
            break;
    case '*':
        return x * y;
            break;
    case '/':
        return x / y;
            break;
    default:
        return 0;
    }
}
std::string infx2pstfx(std::string inf) {
  TStack <char, 100> st1;
  std::string st;
  for (size_t i = 0; i < inf.size(); i++) {
    if ((operat(inf[i]) == -1) && (operat(inf[i]) != 1)) {
      if (!st.empty() && operat(inf[i - 1]) != -1) {
        st.push_back(' ');
      }
      st.push_back(inf[i]);
    } else if ((operat(inf[i]) > operat(st1.get()))
               || (st1.isEmpty()) || (operat(inf[i]) == 0)) {
      st1.push(inf[i]);
    } else {
      if (operat(inf[i]) == 1) {
        while (operat(st1.get()) != 0) {
          st.push_back(' ');
          st.push_back(st1.get());
          st1.pop();
        }
        st1.pop();
      } else {
        while (operat(st1.get()) >= operat(inf[i])) {
          st.push_back(' ');
          st.push_back(st1.get());
          st1.pop();
        }
        st1.push(inf[i]);
      }
    }
  }
  while (!st1.isEmpty()) {
    st.push_back(' ');
    if (operat(st1.get()) != 0) {
      st.push_back(st1.get());
    }
    st1.pop();
  }
  return st;
}

int eval(std::string postov) {
    TStack<int, 100> st2;
    int z = 0;
    int x = 0;
    int y = 0;
for (int i = 0; i < postov.length(); i++) {
        if ((operat(postov[i]) == -1) && postov[i] != ' ') {
            st2.push(postov[i] - '0');
        } else if (operat(postov[i]) > 1) {
            y = st2.get();
            st2.pop();
            x = st2.get();
            st2.pop();
            st2.push(calcul(postov[i], x, y));
        }
    }
    z = st2.get();
  return z;
}
