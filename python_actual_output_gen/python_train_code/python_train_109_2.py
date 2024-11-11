z=input
z()
l=sorted(map(int,z().split()))
l=l[::-1]
e=[]
o=[]
for i in l:
    if i%2==0:
        e.append(i)
    else:
        o.append(i)
om=len(o)
em=len(e)
c=min(om,em)

if om>em:
    l1=o[c+1:]+e[c:]
if em>om:
    l1=e[c+1:]+o[c:]
else:
    l1=e[c:]+o[c:]
    
print(sum(l1))
    

    
