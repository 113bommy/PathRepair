N = int(input())
inputs = [[int(i) for i in input().split()] for _ in range(N)]

ans = 1
rates = {0: 0}
for i in range(N):
    for j in range(N):
        if i == j:
            continue
        vector = (inputs[i][0] - inputs[j][0], inputs[i][1] - inputs[j][1])
        rates[vector] = rates.get(vector, 0) + 1

print(N - max(rates.values()))
