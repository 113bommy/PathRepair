n = int(input())
s = [input() for i in range(n)]
for k in ['AC', 'WA', 'TLE', 'RE']:
    print(k, 'x', s.count(k))