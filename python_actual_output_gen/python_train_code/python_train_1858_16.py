# B

n,m = map(int,input().split())

ln = list(map(int,input().split()))
lm = list(map(int,input().split()))

g = [0 for i in range(n)]
b = [0 for i in range(m)]

for i in range(1,len(ln)):
    g[ln[i]] = 1
for i in range(1,len(lm)):
    b[lm[i]] = 1
for i in range(m*n+1):
    if g[i%n] == 1:
        b[i%m] = 1
    if b[i%m] == 1:
        g[i%n] = 1
if 0 in g or 0 in b:
    print("No")
else:
    print("Yes")