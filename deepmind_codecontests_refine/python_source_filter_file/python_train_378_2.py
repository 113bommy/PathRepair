n = int(input())
figures = list(map(int, input().split()))
res1 = 0
for i in range(n // 2):
    res1 += abs(figures[i] - i * 2 - 1)
res2 = 0
for i in range(n // 2):
    res2 += abs(figures[i] - i * 2 - 2)
print(min(res1, res2))