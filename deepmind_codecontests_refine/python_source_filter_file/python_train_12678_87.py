n,a,b = map(int,input().split())
ans = a*(n//(a+b)) + min(N%(a+b),a)
print(ans)