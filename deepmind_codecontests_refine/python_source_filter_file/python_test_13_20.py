from collections import Counter

for _ in range(int(input())):
    s = list(input())
    c = Counter(s)
    if c['B']>=c['A']+c['C']:
        print('YES')
    else:
        print('NO')
