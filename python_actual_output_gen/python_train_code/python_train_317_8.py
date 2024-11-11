input()
ms=[int(i) for i in input().split()]
c=0
for m in ms:
 if m<=c:
  c=m
  d+=1
print(d)