n, k, s = int(input()), 0, 0
for i in input().split():
    j = int(i[-3: ])
    if j == 0: k += 1
    else: s += j
c = s // 1000 + int(s % 1000 > 500)
a, b = max(0, n - k), min(2 * n - k, n)
if a <= c <= b: s = abs(c * 1000 - s)
else: s = min(abs(a * 1000 - s), abs(b * 1000 - s))
print(str(s // 1000) + '.' + str(s % 1000).zfill(3))