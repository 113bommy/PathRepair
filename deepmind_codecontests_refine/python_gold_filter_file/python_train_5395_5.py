n=int(input())
x=0
for i in range(1,n+1,2):
  c=0
  for j in range(1,n//2+1):
    if(i%j==0):c+=1
  if(c==7):x+=1
print(x)
