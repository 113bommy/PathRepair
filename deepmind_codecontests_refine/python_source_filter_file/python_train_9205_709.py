import math
s=input()
c=0
d=12
arr=[int(x) for x in s.split()]
for i in arr:
  c=c^i
print(c)

