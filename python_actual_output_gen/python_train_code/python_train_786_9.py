r=0
d=0
s=0
n, m = map(int,input().split())
l = n-1
u = m-1
for i in range(n):
    line = input()
    for j, c in enumerate(line):
        if c == 'B':
            s = s+1
            l = min(l, j)
            r = max(r, j)
            d = max(d, i)
            u = min(u, i)
a = max(r-l+1, d - u+1, 1)
#print(l, r, d, u, s, n, m, a)
if a < 0 or a> n or a > m:
    print(-1)
else:
    print(a*a-s)