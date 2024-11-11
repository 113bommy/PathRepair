a,b=input().split()
a,b=int(a),int(b)
c=input().split()
if c.index(c[b-1])>0:
    print(c.index(c[b-1])+c.count(c[b-1]))
else:
    print((c.index(min(c))+c.count(min(c)))-c.count('0'))