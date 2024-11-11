import sys
import math

s = input()
l = len(s)
n = int(input())
v = []
res = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"
for i in range(n):
    st = input()
    k = 0
    fl = True
    if(len(st) != l):
        continue
    for j in s:
        if(j != st[k]):
            fl = False
            break
        k += 1
    if(fl):
        if(st < res):
            res = st
if(res == "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"):
    print(s)
else:
    print(res)

       