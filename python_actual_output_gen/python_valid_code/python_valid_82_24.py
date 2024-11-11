n = int(input())
states = list(map(lambda b: int(b) == 1, list(input())))
ab = list([list(map(int, input().split())) for _ in range(n)])
res = 0
for t in range(10001):
    for i in range(n):
        if t - ab[i][1] > 0 and (t - ab[i][1]) % ab[i][0] == 0:
            states[i] = not states[i]
    res = max(res, states.count(True))
print(res)