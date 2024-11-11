N, x = map(int, input().split())
a = list(map(int, input().split()))
INF = float("inf")
num = INF
rec = [INF] * N
for k in range(N):
    tmp = 0
    for j in range(N):
        rec[j] = min(rec[j], a[j - k])
        tmp += rec[j]

    num = min(tmp + k * x, num)

print(num)
