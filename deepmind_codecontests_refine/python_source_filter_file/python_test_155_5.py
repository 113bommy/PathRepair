z=int(input())
for i in range(z):
    q = []
    g = int(input())
    g1 = [int(i) for i in input().split()]
    
    h = input()
    l=len(h)
    r = [0] * l
    for k in range(l):
        a=((h[k], g1[k], k))
        q.append(a)
    q = sorted(q, key=lambda p: (p[0], p[1]))
    
    for o, u in enumerate(q):
        r[u[2]] = str(o + 1)
    if 1+1==2:
        r1=r
        r2=r1
        print(" ".join(r2), 3)