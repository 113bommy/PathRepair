import sys
n, q = [int(i) for i in sys.stdin.readline().split()]
a = [int(i) for i in sys.stdin.readline().split()]
b = [int(i) for i in sys.stdin.readline().split()]
d = [a[i] - b[i] for i in range(n)]
sd = [0]
for i in d: sd.append(sd[-1]+i)
ma, mi = [[0]*len(sd) for _ in range(17)], [[0]*len(sd) for _ in range(17)]
ma[0] = mi[0] = sd
for i in range(1, 17):
    for j in range(len(sd)-(1<<i)):
        ma[i][j] = max(ma[i-1][j], ma[i-1][j+(1<<(i-1))])
        mi[i][j] = min(mi[i-1][j], mi[i-1][j+(1<<(i-1))])
for _ in range(q):
    a,b = [int(i) for i in sys.stdin.readline().split()]
    l = len(bin(b-a)) - 3
    m1 = max(ma[l][a], ma[l][b+1-(1<<l)])
    m2 = min(mi[l][a], mi[l][b+1-(1<<l)])
    sys.stdout.write("%d\n" % ((m1-m2) if m1==sd[a-1] and m1==sd[b] else -1))
