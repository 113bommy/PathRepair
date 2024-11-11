import sys
n, a, b, c = map(int, input().split())
leastCut = min(a, b, c)
pieces = [None] * (n+1)
pieces[0] = 0
for i in range(1, n+1):
    if i < leastCut:
        pieces[i] = -1
    p = q = r = -1
    if i-a >= 0:
        p = pieces[i-a] + 1
    if i-b >= 0:
        q = pieces[i-b] + 1
    if i-c >= 0:
        r = pieces[i-c] + 1
    pieces[i] = max(p,q,r)
print(pieces[n]) 



