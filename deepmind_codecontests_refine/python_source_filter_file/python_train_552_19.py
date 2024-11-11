

n, k = map(int, input().split())

ranking = {}

for _ in range(n):
    a, b = map(int, input().split())
    if (a, b) in ranking:
        ranking[(a, b)] += 1
    else:
        ranking[(a, b)] = 1

tab = [x[1] for x in sorted(ranking.items(), key=lambda x: (-x[0][0], x[0][1]))]

result = 0

s = 0
for e in tab:
    if s + e < k - 1:
        s += e
    else:
        result = e
        break

print(result)
