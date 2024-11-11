n = int(input())
s = [input() for i in range(n)]
for i in ['AC', 'WA', 'TLE', 'RE']:
    print(i, 'x',  s.count(i))