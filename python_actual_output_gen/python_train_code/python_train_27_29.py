N = int(input())
s = [input() for i in range(N)]
for v in ['AC', 'WA', 'TLE', 'RE']:
  print('{0}×{1}'.format(v, s.count(v)))