n,k=map(int,input().split())
i=1
while n>0:
  i+=1
  n//=k 
print(i)