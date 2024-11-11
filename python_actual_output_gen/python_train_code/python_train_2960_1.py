n,k=map(int,input().split())
l=list(map(int,input().split()))
m=list(map(int,input().split()))
c=0
s=0
for i in range(n):
    if(l[i]<m[i]):
        s+=l[i]
        c+=1 
if(c>=k):
    for i in range(n):
        if(l[i]>m[i]):
            s+=m[i] 
    print(s)
else:
    r=k-c 
    p=[]
    for i in range(n):
        if(l[i]>m[i]):
            p.append((abs(l[i]-m[i]),i))
    p.sort()
    #print(p)
    for i in range(r):
        s+=l[p[i][1]]
        m[p[i][1]]=0 
    #print(s)    
    for i in range(n):
        if(l[i]>m[i]):
            s+=m[i]
    print(s)        

        