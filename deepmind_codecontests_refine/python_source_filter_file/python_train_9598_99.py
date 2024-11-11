n,a,b = map(int,input().split())
print(n - max(a+b,n-b)+1)