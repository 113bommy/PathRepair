n = int(input())
a = list(map(int, input().split()))

d = [0] * 100002
for aa in a:
    d[aa] += 1

dp = [0, 0, 0]
for i in range(1, 100001):
    points = d[i] * i
    dp.append(points + max(dp[-2], dp[-3]))

sol = max(dp[-2:-1])
print(sol)
