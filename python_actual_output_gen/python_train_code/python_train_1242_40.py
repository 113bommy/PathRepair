n,m = map(int,input().split())
if (n-m)<(m-1):
    print(max(m-1,1))
else:
    print(min(m+1,n))