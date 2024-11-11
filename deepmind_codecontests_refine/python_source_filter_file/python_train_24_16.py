tc=int(input())
for _ in range(tc):
    n=int(input())
    a=list(map(int,input().split()))
    i,j,k=0,1,n-1
    if a[i]+a[j]<a[k]:
        print(i+1,j+1,k+1)
    else:
        print(-1)
    
