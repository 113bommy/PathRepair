n = int(input())
l = []
m= []
o=[]
for i in range(n):
    x = input()
    t = x.replace(" ",'')
    o.append(t)
    a = set(o)
    
    y= x.split().pop(0)
    z = x.split().pop(1)
    l.append(y)
    m.append(z)
    p = set(l)
    q = set(m)
if len(p)==len(q):
    print(len(p))
else:
    
    print(len(a))
      