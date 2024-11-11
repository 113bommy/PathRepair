# import os

n = int(input())

gems = {'purple':'Power', 'green':'Time', 'blue': 'Space',
    'orange': 'Soul', 'red': 'Reality', 'yellow': 'Mind'}

gems_in = []
for _ in range(n):
    gems_in.append(input())

print(n-len(gems_in))
r = list(set(gems) - set(gems_in))
for gem in r:
    print(gems[gem])
