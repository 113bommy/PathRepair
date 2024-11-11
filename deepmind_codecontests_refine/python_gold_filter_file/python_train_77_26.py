n = int(input())
a = [input() for i in range(n)]
for v in ['AC', 'WA', 'TLE', 'RE']:
    print('{0} x {1}'.format(v, a.count(v)))