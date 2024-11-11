t=int(input())
for s in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    b=[i for i in range(1,n+1)]
    c=[]
    add=0
    for i in range(n):
        if(a[i]!=b[i]):
            c.append(b[i])
            add+=1
    if(add==0):
        print(0)
    elif(add==n):
        print(1)
    else:
        flag=0
        for i in range(add-1):
            if(c[i]+1!=c[i+1]):
                flag=-1
                break
        if(flag==-1):
            print(2)
        else:
            print(1)