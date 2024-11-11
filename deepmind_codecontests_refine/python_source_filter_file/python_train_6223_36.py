a=input()
b=input()
c=999

for i in range(len(a)-len(b)+1):
  d=0
  for j in range(len(b)):
    if a[i+j]!=b[j]:
      d+=1
  if d<c:
    c=d
print(c)    