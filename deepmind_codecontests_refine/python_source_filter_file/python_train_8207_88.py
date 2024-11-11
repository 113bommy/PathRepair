x = int(input())
s = x//11*2
x = x%11
if x>5:
  s += 2
elif x>0:
  s += 1
print(s)
