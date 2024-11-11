x = int(input())
s = (x//11)*2
x = x%11
if x>=6:
  s += 1
if x>0:
  s += 1
print(s)