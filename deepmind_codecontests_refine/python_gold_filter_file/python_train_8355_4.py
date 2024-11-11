t=int(input())
for i in range(t):
    n,x,y=map(int,input().split())
    dif=y-x
    i=n-1
    l=[]
    while i>=1:
        if dif%i==0:
            p=dif//i
            break
        i-=1
    z=x
    while z<=y:
        l.append(z)
        z+=p
 
    
    z=x-p
    c=len(l)

    while z>=1 and c<n:
        l.append(z)
        z=z-p
        c+=1
        

    z=y+p
    while c<n:
        l.append(z)
        z+=p
        c+=1
    print(*l)