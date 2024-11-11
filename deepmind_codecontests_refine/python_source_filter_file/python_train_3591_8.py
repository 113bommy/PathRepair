n,m = map(int,input().split())


if m==n:
    print (1)
if m > n-m:
    print(m-1)
else:
    print(m+1)
