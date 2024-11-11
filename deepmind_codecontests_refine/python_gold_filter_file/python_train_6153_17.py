n, d = map(int, input().split())
m = int(input())
for _ in range(m):
    x, y = map(int, input().split())
    print('YES' if abs(x - y) <= d and abs(x + y - n) <= n - d else 'NO')
