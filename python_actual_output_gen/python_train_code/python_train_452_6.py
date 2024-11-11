t=int(input())
for j in range(t):
    n=int(input())
    l=list(map(int,input().split()))
    g=[]
    for i in range(n-1):
        if(l[i+1]>0 and l[i]<0):
            g.append(i)
        elif(l[i+1]<0 and l[i]>0):
            g.append(i)
    h=[]
    a=0
    if(len(g)!=0):
        for i in range(len(g)):
            b=max(l[a:g[i]+1])
            h.append(b)
            a=g[i]+1
        h.append(max(l[a:]))
        print(sum(h))
    else:
        print(-1)
    
    
        
    
    