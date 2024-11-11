def mul():
    return list(map(int,input().split()))
def sin():
    return int(input())
t = sin()
l = mul()
e = []
o = []
for i in range(int(t/2)):
    o.append(2*i+1)
    e.append(2*(i+1))
z0 = zip(l,o)
z1 = zip(e,l)
ec,oc = 0,0
for a,b in z0:
   
    oc+=abs(a-b)
for a,b in z1:
    
    ec+=abs(a-b)
print(min(ec,oc))
    
    
    
    
