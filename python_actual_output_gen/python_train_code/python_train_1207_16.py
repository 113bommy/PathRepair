n,m=map(int,input().split())
s=str(input())
ll=list(s)
for i in range(m):
    l,r,c1,c2=input().split()
    l1=int(l)
    r1=int(r)
    if l1==r1:
        for i in range(l1-1,r1):  
            if c1==ll[i]:  
                ll[i]=c2 
                                     
    else:
        for i in range(l1-1,r1-1):
            if c1==ll[i]:
                ll[i]=c2 
print(''.join(ll))      