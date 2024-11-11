n, x = map(int, input().split())
a = [int(m) for m in input().split()]
#x=kのときを考える
#f(i,k)を考える，メモ化しておく
memos = []
for k in range(n):
    memos.append([float("INF") for i in range(n)])

def f(i,k):
    if k == 0:
        memos[k][i] = a[i]
        return a[i]
    if memos[k][i] != float("INF"):
        return memos[k][i]
    else:
        memos[k][i] = min(f(i, k - 1), a[i - k])
        return memos[k][i]

ansli = []
tmpsum = 0
for k in range(n):
    for i in range(n):
        tmpsum += f(i, k)
    ansli.append(x * k + tmpsum)
    tmpsum = 0

print(min(ansli))