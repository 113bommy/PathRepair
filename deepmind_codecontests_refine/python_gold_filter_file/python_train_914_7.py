input()
ms=[int(i) for i in input().split()]
c=d=0
for m in ms:
 if c<=m:
  c=m
  d+=1
print(d)