n=int(input())
l=[]
for i in range(105,n+1):
  c=0
  for j in range(1,i+1):
    if i%j==0:
      c+=1
  if c==8:
    l.append(i)
print(len(l))