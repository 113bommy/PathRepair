

n, b = map(int, input().split())

b = float(b)

mugs = [int(x) for x in input().split()]

b += sum(mugs)

portion = b / n

good = True

result = []

for a in mugs:
    if portion - 1e-9 < a:
        good = False
    else:
        result += [portion - a]

if good:
    print('\n'.join(map(lambda x: '%6f' % x, result)))
else:
    print("-1")
