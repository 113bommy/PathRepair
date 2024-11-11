import sys,bisect
for _ in range(int(sys.stdin.readline())):
    n, m = [int(_) for _ in sys.stdin.readline().split()]
    s = [int(_) for _ in sys.stdin.readline().split()]
    s = sorted([*zip(s, list(range(1, n*m+1)))])
    r = 0
    for i in range(n):
        x = sorted(s[i*m:(i+1)*m], key=lambda x:(x[0], -x[1]))
        sl = []
        for _,j in x:
            idx = bisect.bisect_left(sl, j)
            r+=idx
            sl.insert(idx,j)
    sys.stdout.write('%d\n'%r)