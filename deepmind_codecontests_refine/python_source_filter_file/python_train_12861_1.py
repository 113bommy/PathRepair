t = [k ** 3 for k in range(2, 100000)]
s = m = int(input())
a, b = 1, 9 * m
while a < b:
    c = (a + b) // 2
    d = sum(int(c / k) for k in t)
    if d < m: a = c + 1
    else: s, b = d, c
print(a if s == m else -1)