t=int(input())
for i in range(t):
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    li=[]
    for i in range(n):
        li.append([a[i],i])
    li.sort()
    b=sorted(a)
    c=0
    if n==1:
        print("Yes")
    
    elif a==b:
        print("Yes")
    else:
        c=1
        for i in range(1,n):        
            if (li[i][1]-i)!=(li[i-1][1]-(i-1)):
                c+=1
        if c<=k:
            print("Yes")
        else:
            print("No")