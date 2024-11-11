M=10**9+7
n=int(input())
l=list(map(int,input().split()))
a=0
for i in range(60):
  t=sum(j>>i&1 for j in l)
  a+=(t*(n-t)<<i)%M
print(a%M)