import sys
input = sys.stdin.readline
n, m = map(int, input().split())
a = [0] * n
for _ in range(m):
    x, y = map(int, input().split())
    a[x] = (a[x] + 1) & 1
    a[y] = (a[y] + 1) & 1
print("YES" if sum(a) == 0 else "NO")
