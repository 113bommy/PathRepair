t=int(input())
for i in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    sa=sorted(a)
    j=0
    while a!=sa:
        if (j+1)%2:
            for k in range(0,n-2,2):
                if a[k]>a[k+1]:
                    a[k],a[k+1]=a[k+1],a[k]
        else:
            for k in range(1,n-1,2):
                if a[k]>a[k+1]:
                    a[k],a[k+1]=a[k+1],a[k]
        j+=1
    print(j)