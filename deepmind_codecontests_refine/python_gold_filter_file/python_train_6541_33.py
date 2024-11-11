import operator
N, C = map(int, input().split())
stc = [[int(x) for x in input().split()] for _ in range(N)]

united = []
pc,ps,pt = 0,0,0
for x in sorted(stc, key=operator.itemgetter(2,0,1)):
    s, t, c = x
    if c == pc and s == pt:
        united[-1][1] = t
    else:
        united.append([s, t, c])
    ps, pt, pc = x
cnt = [0] * (10**5 + 1)
for x in united:
    s,t,c = x
    for i in range(s - 1, t):
        cnt[i] += 1
print(max(cnt))