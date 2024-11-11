n=int(input())
b=[input() for _ in range(n)]
m=int(input())
r=[input() for _ in range(m)]
l=list(set(b))
a=[]
for s in l:
    a.append(b.count(s) - r.count(b))
print(max(max(a),0))
