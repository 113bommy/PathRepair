n,m = map(int,input().split())


if m==n==1:
    print (1)
if m > n-m:
    print(m-1)
else:
    print(m+1)
