n, val = int(input()), 0
for x, y in zip((int(x) for x in input().split()), range(1, n + 1)):
    val += abs(x - y)
print(val)