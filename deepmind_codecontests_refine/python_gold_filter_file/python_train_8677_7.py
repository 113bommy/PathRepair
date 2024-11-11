MAXN = 1000001
sq = set()
pr = [1]*MAXN
for i in range(2, MAXN):
    if pr[i] == 1:
        for j in range(i*i, MAXN, i):
            pr[j] = 0
        sq.add(i*i)

n = int(input())
for i in map(int, input().split()):
    if i in sq:
        print("YES")
    else:
        print("NO")


