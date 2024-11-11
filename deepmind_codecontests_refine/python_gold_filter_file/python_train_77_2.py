N = int(input())
S = [input() for i in range(N)]

for item in ['AC', 'WA', 'TLE', 'RE']:
    print("{} x {}".format(item, S.count(item)))