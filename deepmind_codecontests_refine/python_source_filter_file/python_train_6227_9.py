yandy
N, M = list(map(int, input().split()))
data = [list(map(int, input().split())) for _ in range(N)]

data.sort()

price = 0
for d in data:
    price += d[0] * min(M, d[1])
    M -= d[1]
    if M <= 0:
        break
print(price)
