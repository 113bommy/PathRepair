n, m = map(int, input().split())

s = min(n, m)
print(s + 1)
for x in range(s + 1):
    print(x, x)
