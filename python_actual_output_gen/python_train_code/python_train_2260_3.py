n,k=map(int,input().split())
ar=sorted([int(x) for x in input().split()])
if k==0:
    print(-1 if ar[0]==1 else 1)
else:
    if k<n and ar[k-1]!=ar[k]:
        print(-1)
    else:
        print(ar[k-1])