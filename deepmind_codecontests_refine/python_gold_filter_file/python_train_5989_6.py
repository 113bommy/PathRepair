def fac(n):
    
    fact=1
    for i in range(n,0,-1):
        fact*=i
    return fact    
n=int(input())
l=[]
for i in range(n):
    s=list(input())
    l.append(s)
a=[]
b=[]
r=[]
c=[]
ans=0   
for i in range(n):
    c=0
    for j in range(n):
        if l[i][j]=='C':
            c+=1
    a.append(c)        
            
for i in range(n):
    c=0
    for j in range(n):
        if l[j][i]=='C':
            c+=1
    b.append(c)
for i in range(len(a)):
    if a[i]>1:
        z=fac(a[i])//(fac(2)*fac(a[i]-2))
        #print(z)
        ans+=z
for j in range(len(b)):
    if b[j]>1:
        z=fac(b[j])//(fac(2)*fac(b[j]-2))
        #print(z,b)
        ans+=z 
print(ans)        
    
        
                    
            
        