import math
S = int(input())
v = 10**9
x3 = (v-S%v)%v
y3 = (S-x3)//v
print("0 0 %d 1 %d %d"%(10**9, x3, y3))