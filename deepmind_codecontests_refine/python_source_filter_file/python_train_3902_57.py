m, n = map(int, input().split())

p = []
for i in range(1,m+1):
    if i % 2 != 0:
        p.append(['#'] * n)
    elif i % 4 == 0:
        p.append(['#'] + ['.']*(n-1))
    else:
        p.append(['.']*(n-1) + ['#'])

for el in p:
    for il in el:
        print(il, end=' ')
    print()