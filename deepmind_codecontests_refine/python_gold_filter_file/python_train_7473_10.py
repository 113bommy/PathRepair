mod=10**9+7
n=int(input())
arr=list(map(int,input().split()))
arr=sorted(arr)
ans=0
for i in range(n):
  ans+=pow(2,2*n-2,mod)*(n-i+1)*arr[i]
  ans%=mod
print(int(ans))