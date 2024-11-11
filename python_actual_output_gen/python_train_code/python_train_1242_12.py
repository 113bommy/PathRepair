n,m = map(int,input().split())
if m-1 > n-m:
    print(m-1)
else:
    print(min(m+1,n))