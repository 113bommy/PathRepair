#!/bin/python3
import sys
a = input();
b = input()
ai = 0
bi = 0
while ai < len(a) and a[ai] == '0':
    ai+=1
while bi < len(b) and b[bi] == '0' :
    bi+=1
l1 = len(a) - ai
l2 = len(b) - bi
if l1 > l2:
    print(">")
    sys.exit()
if l1 < l2:
    print("<")
    sys.exit()
if a[ai:] > b[bi:]:
    print(">")
elif a[ai:] < b[bi:]:
  print(">")
else:
  print("=")
    