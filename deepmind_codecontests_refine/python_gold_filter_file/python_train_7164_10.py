import itertools

n,m,q = map(int,input().split())

lr = [[0 for i in range(n)] for j in range(n)]
for _ in range(m):
    l,r = map(int,input().split())
    lr[l-1][r-1] += 1

acc_lr = []
for l in lr:
    acc_lr.append([0] + list(itertools.accumulate(l)))

for _ in range(q):
    l,r = map(int,input().split())
    ans = 0
    for ls in acc_lr[l-1:r]:
        ans += ls[r] - ls[l-1]
    print(ans)
