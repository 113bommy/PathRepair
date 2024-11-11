n,k=map(int,input().split())
A=list(map(int,input().split()))

cnt=0
a=0

if n==1:print(0)
else:
  for i in range(n-1):
    for j in range(i+1,n):
      if A[i]>A[j]:
        cnt+=1

  for i in range(n):
    for j in range(n):
      if A[i]>A[j]:
        a+=1

      
print(int(cnt*k+a*(k*(k-1)//2))%(10**9+7))
