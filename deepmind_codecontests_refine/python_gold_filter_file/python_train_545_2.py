n=int(input())
l=list(map(int,input().split()))
r=[]
if(n==1):
    print(1,1)
    print(-l[0])
    print(1,1)
    print(0)
    print(1,1)
    print(0)
else:
    for i in l:
           r.append(n-(i%n))

    ans=[]
    print(1,n-1)
    for i in range(n-1):
        if(l[i]>=0):
            ans.append(-(l[i]+(n-1)*(n-r[i])))
            print((n - 1) * (n - r[i]),end=" ")
        else:
            ans.append(-(l[i]+(n-1)*(n-r[i])))
            print((n-1)*(n-r[i]),end=" ")
    print()
    print(n,n)
    print(-l[n-1])
    print(1,n)
    ans.append(0)
    print(*ans)
