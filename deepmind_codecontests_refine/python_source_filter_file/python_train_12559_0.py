T = int(input())
for _ in range(T):
    n = int(input())
    studs = [list(map(int,input().split())) for _ in range(n)]
    t = 0
    out = [0]*n
    cs = 0
    while len(studs)>0:
        t += 1
        if studs[0][0]<=t and studs[0][1] > t:
            out[cs] = t
            cs += 1
            studs.pop(0)
        elif studs[0][0] <= t:
            cs += 1
            studs.pop(0)
            t -= 1
    print(' '.join(map(str,out)))
