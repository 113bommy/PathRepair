n,m=map(int,input().split())
if n-m>=m:
    print(min(n,m+1))
else:
    print(max(0,m-1))