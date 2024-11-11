n = int(input())
p = list(map(int, input().split()))
x = 0
y = 0
for i in range(n // 2):
    p[i] -= 1
    x += abs(p[i] - 2 * i)
    y += abs(p[i] - 2 * i - 1)
print(min(x, y))
