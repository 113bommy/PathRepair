1 N = int(input())
2 s = [input() for i in range(N)]
3 for v in ['AC', 'WA', 'TLE', 'RE']:
4 print('{0} x {1}'.format(v, s.count(v)))