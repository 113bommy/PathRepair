n,m=map(int,input().split())
a=[int(input()) for i in range(m)]
a=set(a)
A=[0]*(n+1)
A[0]=1
for i in range(1,n+1):
  if i in a:
    A[i]==0
  else:
    A[i]=A[i-1]+A[i-2]
print(A[n]%(10**9+7))