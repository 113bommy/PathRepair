for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    if(a.count(a[0])==n):
        print(-1)
    else:
        x=max(a)
        for i in range(n):
            if(a[i]==x and i+1<n and a[i+1]<x):
                print(i+1)
                break
            if(a[i]==x and i-1>=0 and a[i-1]<x):
                print(i+1)
                break