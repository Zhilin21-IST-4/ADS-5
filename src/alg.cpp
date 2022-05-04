// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int pr(char myoperator1) {
  switch (myoperator1) {
    case '(': return 0;
    case ')': return 1;
    case '+': return 2;
    case '-': return 2;
    case '/': return 3;
    case '*': return 3;
    case ' ': return 5;
    default: return 4;
  }
}

int calculator(char myoperator, int a, int b) {
  switch (myoperator) { 
    case '+': return (b + a);
    case '-': return (b - a);
    case '*': return (b * a); 
    case '/':
    if (a != 0) {
      return b / a;
    }
    default: return 0;
  }
}

std::string infx2pstfx(std::string inf) {
  std::string var1;
  TStack <char, 100> SMT;
  int j = 0;
  for (int j = 0; j < inf.size(); j++) {
    if (pr(inf[j]) == -2) {
      var1.push_back(inf[j]);
      var1.push_back(' ');
    } else {
      if (pr(inf[j]) == 0) {
        SMT.push(inf[j]);
      } else if (SMT.isEmpty()) {
        SMT.push(inf[j]);
      } else if ((pr(inf[j]) > pr(SMT.get()))) {
        SMT.push(inf[j]);
      } else if (pr(inf[j]) == 1) {
        while (pr(SMT.get()) != 0) {
          var1.push_back(SMT.get());
          var1.push_back(' ');
          SMT.pop();
        }
        SMT.pop();
      } else {
        while (!SMT.isEmpty() && pr(inf[j]) <= pr(SMT.get())) {
          var1.push_back(SMT.get());
          var1.push_back(' ');
          SMT.pop();
        }
        SMT.push(inf[j]);
      }
    }
  }
  while (!SMT.isEmpty()) {
    var1.push_back(SMT.get());
    var1.push_back(' ');
    SMT.pop();
  }
  int i = 0;
  for (int i = 0; i < var1.size(); i++) {
    if (var1[var1.size() - 1] == ' ')
      var1.erase(var1.size() - 1);
  }
  return var1;
}

int eval(std::string pref) {
  int resultat = 0;
  TStack <int, 100> SMT1;
  int k = 0;
  for (int k = 0; k < pref.size(); k++) {
    if (pr(pref[k]) == -2) {
      SMT1.push(pref[k] - '0');
    } else if (pr(pref[k]) < 4) {
      int x1 = SMT1.get();
      SMT1.pop();
      int x2 = SMT1.get();
      SMT1.pop();
      SMT1.push(calculator(pref[k], x1, x2));
    }
  }
  resultat = SMT1.get();
  return resultat;
}
