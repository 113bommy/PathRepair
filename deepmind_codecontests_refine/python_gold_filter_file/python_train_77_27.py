n = int(input())
s = [input() for _ in range(n)]

for i in ['AC', 'WA', 'TLE', 'RE']:
    print('{} x {}'.format(i, s.count(i)))