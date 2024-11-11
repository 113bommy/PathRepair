n = int(input())
a = [int(x) for x in input().split()]
e = []
o = []
for i in a:
  if i%2==0:
    e.append(i)
  else:
    o.append(i)

print(a.index(min(e,o,key=len)[0])+1)
