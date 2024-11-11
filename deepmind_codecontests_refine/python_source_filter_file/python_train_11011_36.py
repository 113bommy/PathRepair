n,k=map(int,input().split())
a=list(map(int,input().split()))
for i in range(k):
  b=[0]*(n+1)
  for j in range(n):
    b[max(0,j-a[j])]+=1
    b[min(n,j+a[j]+1)]-=1
  for j in range(n):
    b[j+1]+=b[j]
  a=b[:-1]
  if a==[n]*n:exit(print(*a))
print(*a)