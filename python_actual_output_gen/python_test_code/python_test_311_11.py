n = int(input())
balls = list(map(int, input().split()))

balls = set(balls)
balls = sorted(balls)
res = "NO"
for i in range (1, len(balls) - 2):
    if ((balls[i] - balls[i - 1]) <= 2) and ((balls[i + 1] - balls[i]) <= 2) and ((balls[i + 1] - balls[i - 1]) <= 2):
        res = "YES"
print(res)