t=int(input())
s=[]
for jjh in range(0,t):
    n,x=map(int,input().split( ))
    def men(b):
        return(b-x)
    p=reversed(sorted(list(map(int,input().split( )))))
    p=list(map(men,p))
    q=0
    for i in range(0,n):
        q+=p[i]
        if q<0:
            s.append(i)
            break
    if i==n-1:
        s.append(n)
for i in s:
    print(i)
    
