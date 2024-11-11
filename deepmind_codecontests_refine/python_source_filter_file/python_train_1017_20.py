a,b,c=  map(int,input().split())
M = 10**9
if c == M:l = [c]*b+[1]*a
else:l = [c]*b+[M]*a

print(*l)