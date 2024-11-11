n,m = map(int,input().split())
if n==0:
    if m==0:
        print(0,0)
    else:
        print("Impossible")
else:
    print(n+max(0,m-n),n+max(0,m-1))