from itertools import product
n, k = list(map(int, input().split()))
al = list(map(int, input().split()))
INF = float("inf")
ans = INF
for bit in product([0, 1], repeat=(n-1)):
    if sum(bit)+1 >= k:
        t = 0
        pre = al[0]
        for i, a in enumerate(al):
            if i != 0:
                if bit[i-1] == 1:
                    t += max(0, (pre+1)-al[i])
                    pre = max(al[i], pre+1)
                    continue
                pre = max(pre, al[0])
        ans = min(ans, t)
print(ans)
