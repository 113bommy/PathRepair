n=int(input())

s=input()
r,b,g=[],[],[]
sb=sg=sr=0
for i in s:
    if i=='R':
        sr=sr+1
        b.append(sb)
        g.append(sg)
        sb=sg=0
    elif i=='G':
        sg=sg+1
        b.append(sb)
        r.append(sr)
        sr=sb=0
    elif i=='B':
        sb=sb+1
        g.append(sg)
        r.append(sr)
        sr=sg=0
        
  
  


r.append(sr)
b.append(sb)
g.append(sg)



#print(r,b,g)
s=0
for i in r:
    if i!=0:
        s=s+i-1
        
for i in b:
    if i!=0:
        s=s+i-1
        
for i in g:
    if i!=0:
        s=s+i-1
        
print(s)