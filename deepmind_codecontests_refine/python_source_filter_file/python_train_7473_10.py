mod=10**9+7
n=int(input())
arr=list(map(int,input().split()))
arr=sorted(arr)
ans=0
for i in range(n):
  ans+=pow(2,2*n-1,mod)*(1+(n-i-1)/2)*arr[i]
  ans%=mod
print(int(ans))