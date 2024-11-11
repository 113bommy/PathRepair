n,k=map(int,input().split())
mi=1
if k==0:
    print(0,0)
    exit()
if k==n:
    print(0,0)
    exit()
if 2*k <n:
    ma=k+1
else:
    ma=n-k
print(mi,ma)
