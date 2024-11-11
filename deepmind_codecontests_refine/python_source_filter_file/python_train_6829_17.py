n,k=map(int, input().split())
if (k+1)<=n//2:
        print((n//2)//(k+1),((n//2)//(k+1))*k,n-(k+1)*((n//2)//(k+1)))
else:
        print(0,0,k)
