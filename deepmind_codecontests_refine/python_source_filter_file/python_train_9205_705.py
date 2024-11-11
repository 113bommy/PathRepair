import math
s=input()
a=12
c=0
arr=[int(x) for x in s.split()]
for i in arr:
  c=c^i
print(c)

