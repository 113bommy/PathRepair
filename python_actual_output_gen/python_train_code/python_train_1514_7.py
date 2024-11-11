from sys import stdin
inp=lambda:stdin.readline()
insp=lambda:inp().split()
n=int(inp())
b={}
for i in insp():
    i=int(i)
    b[i]=b.setdefault(i,0)+1
c=sorted(b.keys())
o=b[c.pop(0)]
sad=0
for i in c:
    sad+=max(0,b[i]-o)
    o=max(b[i],o)
print(n-sad-o)
