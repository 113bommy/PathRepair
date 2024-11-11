n, w = map(int, input().split())
a = list(map(int, input().split()))

temp = sorted(a)

m = min(temp[0], temp[2 * n - 1] / 2)

total = 3 * m * n

print(min(total, w))

