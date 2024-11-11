t = int(input())
for w in range(t):
    a, b, x, y = map(int ,input().split())
    print(max(max((b - y - 1) * a, y * a), max((a - x - 1) * b, x * b)))