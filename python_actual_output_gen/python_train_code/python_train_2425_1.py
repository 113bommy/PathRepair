n,m=map(int,input().split())

if n==0 and m==0:
    print ("0")
elif n==0:
    print("Impossible")
elif m==0:
    print(n+m,n+m)
else:
    print(n+m-min(n,m),n+m-1)
    
