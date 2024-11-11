N = int(input())
S = [input() for _ in range(N)]

for r in ['AC', 'WA', 'TLE', 'RE']:
    print('{} x {}'.format(r, S.count(r)))
