n,m=map(int,input().split())
fib=[0]*(n+1)
fib[0]=0
fib[1]=1
for i in range(n-1):
  fib[i+2]=fib[i]+fib[i+1]
ans=1
k=0
for i in range(m):
  a=int(input())
  ans*=fib[a-k]
  k=a+1
ans*=fib[n-k+1]
print(ans%1000000007)