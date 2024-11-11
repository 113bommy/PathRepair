n, m = map(int, input().split())
s = 0
b = 0

while n > 0 and m > 0:
        n -= 1
        m -= 1
        s += 1
if n > 0:
    for i in range(1, n, 2):
        b += 1
else:
    for i in range(1, m, 2):
        b += 1
print(s, b)
