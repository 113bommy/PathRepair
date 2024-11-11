n,m = list(map(int,input().split()))
mod = 10**9+7
print(pow(pow(2,m,mod)-1,n,mod))