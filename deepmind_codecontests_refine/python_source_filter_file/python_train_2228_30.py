n, m = map(int, input().split())
numbers, dif = sorted(int(i) for i in input().split()), 2000
for i in range(m - n):
    dif = min(dif, numbers[i + n - 1] - numbers[i])
print(dif)
