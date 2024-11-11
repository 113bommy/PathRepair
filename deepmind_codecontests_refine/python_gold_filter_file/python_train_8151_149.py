n, k, l, c, d, p, nl, np = map(int,input().split())
m = k*l
x = m/nl
y = c*d
z = p/np
print(int(min(x,y,z)/n))