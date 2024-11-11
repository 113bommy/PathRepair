from sys import stdin
def ii(): return int(stdin.readline())
def mi(): return map(int, stdin.readline().split())
def li(): return list(mi())
def si(): return stdin.readline()
a=ii()
b=ii()
c=ii()
d=ii()
e=ii()
x=max(0, min(a+b, e-(a*(c-1)+b*(d-1))))
if c<d:
    y=min(a, e//c)
    e-=y*c
    y+=min(b, e//d)
else:
    y=min(b, e//d)
    e-=y*d
    y+=min(a, e//c)
print(x, y)