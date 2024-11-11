d = lambda i, j: (t[i][0] - t[j % n][0]) ** 2 + (t[i][1] - t[j % n][1]) ** 2
n = int(input())
t = [list(map(int, input().split())) for q in range(n)]
h = 1e13
for i in range(n):
    a, b, c = d(i - 1, i), d(i, i + 1), d(i - 1, i + 1)
    h = min(h, (4 * a * b - (a + b - c) ** 2) / c)
print(h ** 0.5 / 4)