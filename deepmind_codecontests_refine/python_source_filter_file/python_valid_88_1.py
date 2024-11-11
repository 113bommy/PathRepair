import sys
for _ in range(int(sys.stdin.readline())):
    n, m = [int(_) for _ in sys.stdin.readline().split()]
    s = [int(_) for _ in sys.stdin.readline().split()]
    s = sorted([*zip(s, list(range(1, n*m+1)))])
    r = 0
    for i in range(n):
        x = sorted(s[i*m:(i+1)*m], key=lambda x:(x[0], -x[1]))
        for j in range(m):
            for k in range(j-1):
                r+=x[j][1]>x[k][1]
    sys.stdout.write('%d\n'%r)