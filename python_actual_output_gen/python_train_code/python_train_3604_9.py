N,K=map(int,input().split())
A=list(map(int,input().split()))
A.sort()
a,b,i=0,-1,0
mod=10**9+7
ans=1
while i<K-1:
  if A[a]*A[a+1]>A[-b]*A[-b-1]:
    ans*=A[a]*A[a+1]
    ans%=mod
    a+=2
    i+=2
  else:
    ans*=A[-b]
    ans%=mod
    b+=1
    i+=1
if i==K-1:
  ans*=A[-b]
  ans%=mod
if A[-1]<0 and K%2==1:
  ans=1
  for i in A[N-K:]:
    ans*=i
    ans%=mod
print(ans%mod)