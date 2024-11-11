n, x, y = map(int, input().split())
a = y - n + 1
if a * a + n - 1 < x or a < 0: exit(print(-1))
print(a)
for _ in range(n - 1):
    print(1)

