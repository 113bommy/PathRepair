n,m=map(int,input().split())
a=[]
for i in range(m):
    x=list(map(int,input().split()))
    x.reverse()
    a.append(x)
s=0;y=0
for i in range(m):
    d=max(a)
    if d[1]>=n:
        s=s+(n)*d[0]
        break
    n-=d[1]
    s+=d[1]*d[0]
    a.remove(d)
print(s)
        
    
    
    
    
    
