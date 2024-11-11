for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    d={}
    for i in range(0,n):
        p=bin(a[i])[2:]
        z=len(p)
        if z not in d:
            d[z]=1
        else:
            d[z]+=1
    count=0
    for x in d:
        y=d[x]
        if y>1:
            f=(n*(n-1))//2
            count+=f
    print(int(count))