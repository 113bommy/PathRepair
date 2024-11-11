n = int(input())
s = [input() for i in range(n)]
for v in ('AC', 'WA', 'TLE', 'RE'):
    print('{} x {}'.format(v, s.count(v)))