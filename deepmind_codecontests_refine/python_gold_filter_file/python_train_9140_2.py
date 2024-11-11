N = int(input())
P = map(float, input().split())

dp = [1] + [0] * N
for i, p in enumerate(P, 1):
    dp = [p * a + (1 - p) * b for a, b in zip([0] + dp, dp)]

print(sum(dp[-(-N // 2):]))