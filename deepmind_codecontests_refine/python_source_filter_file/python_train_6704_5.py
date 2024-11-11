from math import sqrt
n = int(input())
resp = set()
for y in range(1, 60):
    delta = 2**(2*y) - (2**(y+1))*3 + 9 + 8*n
    raiz = -1
    l, r = 0, int(sqrt(delta))+10
    while l <= r :
        m = (l+r)//2
        if m*m == delta:
            raiz = m
            break
        elif m*m < delta:
            l = m+1
        else:
            r = m-1
    if raiz == -1:
        continue
    x1 = (3-2**y+raiz)//2
    x2 = (3-2**y-raiz)//2
    if x1 % 2 == 1:
        x1 = x1 * (2**(y-1))
        if x1 >= 1:
            resp.add(x1)
    if x2 % 2 == 1:
        x2 = x2 * (2**(y-1))
        if x2 >= 1:
            resp.add(x2)
if len(resp) == 0:
    print("-1")
else:
    for e in sorted(resp):
        print(e)
 