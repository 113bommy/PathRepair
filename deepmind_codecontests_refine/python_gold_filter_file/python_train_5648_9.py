def push(a,b):
    if(a>b):
        return 
    mid=(a+b)//2
    c.append([b-a,-1*a])
    push(mid+1,b)
    push(a,mid-1)
    




for _ in range(int(input())):
    n=int(input())
    c=[]
    a=[0]*n
    push(0,n-1)
    c.sort(reverse=True)
    # print(c)
    for i in range(n):
        d=c[i][0]//2-c[i][1]
        a[d]=i+1
    print(*a)