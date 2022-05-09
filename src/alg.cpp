// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int pr(char var1) {
  if (var1 == '(') {
    return 0;
  }
  else if (var1 == ')') {
    return 1;
  } 
  else if (var1 == '-') {
    return 2;
  }
  else if (var1 == '+') {
    return 2;
  }
  else if (var1 == '/') {
    return 3;
  }
  else if (var1 == '*') {
    return 3;
  }
  else if (var1 == ' ') {
    return 4;
  } 
  else {
    return -2;
  } 
}

int calculator(char c, int a, int b) {
  if (c == '+') {
    return (b + a);
  }
  else if (c == '-') {
    return (b - a);
  }
  else if (c == '*') {
    return (b * a);
  }
  else if ((c == '/') && (a != 0)) {
    return (b / a);
  }
  else {
    return 0;
  }
}

std::string infx2pstfx(std::string inf) {
  std::string peremen;
  TStack <char, 100> ZZ;
  int j = 0;
  for (int j = 0; j < inf.size(); j++) {
    if (pr(inf[j]) == -2) {
      peremen.push_back(inf[j]);
      peremen.push_back(' ');
  }
    else {
      if (pr(inf[j]) == 0) {
        ZZ.push(inf[j]);
      } 
      else if (ZZ.isEmpty()) {
        ZZ.push(inf[j]);
      }
      else if ((pr(inf[j]) > pr(ZZ.get()))) {
        ZZ.push(inf[j]);
      } 
      else if (pr(inf[j]) == 1) {
        while (pr(ZZ.get()) != 0) {
          peremen.push_back(ZZ.get());
          peremen.push_back(' ');
          ZZ.pop();
        }
        ZZ.pop();
      }
      else {
        while (!ZZ.isEmpty() && pr(inf[j]) <= pr(ZZ.get())) {
          peremen.push_back(ZZ.get());
          peremen.push_back(' ');
          ZZ.pop();
        }
        ZZ.push(inf[j]);
      }
    }
  }
  while (!ZZ.isEmpty()) {
    peremen.push_back(ZZ.get());
    peremen.push_back(' ');
    ZZ.pop();
  }
  int i = 0;
  for (int i = 0; i < peremen.size(); i++) {
    if (peremen[peremen.size() - 1] == ' ')
    peremen.erase(peremen.size() - 1);
  }
  return peremen;
}

int eval(std::string pref) {
  int result = 0;
  TStack <int, 100> XX;
  int k = 0;
  for (int k = 0; k < pref.size(); k++) {
    if (pr(pref[k]) == -2) {
      XX.push(pref[k] - '0');
    }
    else if (pr(pref[k]) < 4) {
      int y = XX.get();
      XX.pop();
      int x = XX.get();
      XX.pop();
      XX.push(calculator(pref[k], y, x));
    }
  }
  result = XX.get();
  return result;
}
