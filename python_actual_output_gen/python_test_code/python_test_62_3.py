q, t = 0, sorted([(len(input()) - 2, i) for i in 'ABCD'])
if 2 * t[0][0] <= t[1][0]: q += 1
if t[3][0] >= 2 * t[2][0]: q += 2
print(['C', t[0][1], t[2][1], 'C'][q])