n = map(int,input().split())
p=[int(x) for x in input().split()]
q=0
c=[]
for i in p:
    a=q
    q+=i
    c.append(q)
    if q<=0:
        q=a
        
print(*c)    
    
    