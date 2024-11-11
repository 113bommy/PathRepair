a = sorted([(len(input()) - 2, i) for i in 'ABCD'])
p = 0
if a[0][0] * 2 <= a[1][0]:
    p += 1
if a[-2][0] * 2 <= a[-1][0]:
    p += 2
print(['C', a[0][0], a[-1][0], 'C'][p])
