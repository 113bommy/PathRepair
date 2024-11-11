n = int(input())
a = [int(x) for x in input().split(' ')]
x = sum(a) // n
m = float('inf')
for i in range(x - 3, x + 4):
    s = 0
    for c in a:
        s += min(abs(c - (i - 1)), abs(c - i), abs(c -(i + 1)))
    if s < m:
        y = i
        m = min(s, m)
print(y, m)
