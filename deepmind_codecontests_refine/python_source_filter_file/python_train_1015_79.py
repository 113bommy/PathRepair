
from collections import defaultdict
from bisect import bisect
n, k = list(map(int, input().split()))
al = [0] * n
for i in range(n):
    al[i] = int(input())
max_al = max(al)
min_al = min(al)
# N: 処理する区間の長さ
N = max(al)+1
N0 = 2**(N-1).bit_length()
INF = 2**31-1
data = [INF]*(2*N0)
# a_k の値を x に更新


def update(k, x):
    k += N0-1
    data[k] = x
    while k >= 0:
        k = (k - 1) // 2
        data[k] = min(data[2*k+1], data[2*k+2])
# 区間[l, r)の最小値


def query(l, r):
    L = l + N0
    R = r + N0
    s = INF
    while L < R:
        if R & 1:
            R -= 1
            s = min(s, data[R-1])

        if L & 1:
            s = min(s, data[L-1])
            L += 1
        L >>= 1
        R >>= 1
    return s


for i in range(n):
    update(al[i], n)

for a in al:
    v = query(max(min_al, a-k), min(a+k+1, max_al))
    update(a, n-((n-v)+1))
v = query(min_al, max_al+1)
print(n-v+1)
