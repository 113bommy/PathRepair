n, w = map(int, input().split())
a = list(map(int, input().split()))

temp = sorted(a)

m = min(temp[0], temp[len(a)-1])
total = 3 * m * n

print(min(total, w))

