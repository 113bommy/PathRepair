N = int(input())
S = [input() for i in range(N)]

for item in ['AC', 'WA', 'TLE', 'RE']:
    print("{} X {}".format(item, S.count(item)))