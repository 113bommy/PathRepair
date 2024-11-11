n,k=map(int,input().split())
a=1
while n > k:
  n//=k
  a+=1
print(a)