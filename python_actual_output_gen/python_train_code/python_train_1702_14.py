a,b,c=[int(i) for i in input().split()]
d=[int(i) for i in input().split()]
e=sorted(d,reverse=True)
f=e[0:b]
g=e[b:]
if(max(g)<min(f)):
    print(max(g))
else:
    print(0)
