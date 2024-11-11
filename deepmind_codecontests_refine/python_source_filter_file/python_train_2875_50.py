n,m=map(int,input().split(" "))
r=0
if(n-m>=1):
    r=1
if(m==0):
    print("0 0")
else:
    if(n-m<=n//2):
        print(r,n-m)
    else:
        print(r,m*2)