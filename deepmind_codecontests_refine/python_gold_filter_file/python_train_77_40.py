n = int(input())
s = [input() for i in range(n)]
for v in ['AC', 'WA', 'TLE', 'RE']:
    print('{0} x {1}'.format(v, s.count(v)))