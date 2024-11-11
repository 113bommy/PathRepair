n,m=map(int,input().split())
 
if n==m:
    print(0)
elif m<n//2:
    if m==0:
        print(1)
    else:
        print(m)
else:
    print(n-m)
