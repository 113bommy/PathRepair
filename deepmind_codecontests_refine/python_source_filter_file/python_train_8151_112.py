n, k, l, c, d, p, nl, np=input().split()

n = int(n)
k = int(k)
l = int(l)
c = int(c)
d = int(d)
p = int(p)
nl = int(nl)
np = int(np)

a = k*l
x= a//nl
y = p//np
z = d

ans = min(x,y,z)//n
print(ans)