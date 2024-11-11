from itertools import combinations as comb

N = int(input())
l = [tuple(map(int, input().split())) for _ in range(N)]
dist = lambda a,b:((a[0]-b[0])**2+(a[1]-b[1])**2)**0.5


def get_centers():
    ans = []
    for a, b, c in comb(l, 3):
        x1, y1 = a
        x2, y2 = b
        x3, y3 = c

        A = 2 * (x2-x1)
        B = 2 * (y2-y1)
        D = 2 * (x3-x2)
        E = 2 * (y3-y2)
        C = x1**2-x2**2+y1**2-y2**2
        F = x2**2-x3**2+y2**2-y3**2

        if B*D-A*E!=0:
            cy = (A*F-C*D)/(B*D-A*E)
            cx = -(F+E*cy)/D if D else -(C+B*cy)/A
            r = dist(a, (cx,cy))
            ans.append((cx, cy, r))

    for a, b in comb(l, 2):
        d = min(a,b)
        e = max(a,b)
        ans.append(((d[0]+e[0])/2, (d[1]+e[1])/2, dist(d,e)/2))

    return ans

if N==2:
    d = l[0]
    e = l[1]
    print(dist(d, e)/2)
else:
    ans = 0
    for xr, yr, r in get_centers():
        v = 0
        for x, y in l:
            v += dist((x,y),(xr,yr))<=r
        if v==N:
            ans = max(ans, r)
    print(ans)