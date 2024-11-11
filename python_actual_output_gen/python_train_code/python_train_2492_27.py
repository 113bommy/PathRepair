t = int(input())
for w in range(t):
    a, b, y, x = map(int ,input().split())
    print(max(max((a - y - 1) * b, y * a), max((b - x - 1) * a, x * a)))