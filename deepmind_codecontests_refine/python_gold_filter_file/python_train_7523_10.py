from itertools import accumulate
from collections import defaultdict

n = int(input())

a = list(map(int, input().split()))

acc = list(accumulate(a))

positions = defaultdict(lambda: [])

for i, val in enumerate(acc):
    positions[val].append(i)
    
intervals = []
    
for val, pos_list in positions.items():
    if val == 0:
        intervals.append((pos_list[0], 0))
    for pos1, pos2 in zip(pos_list, pos_list[1:]):
        intervals.append((pos2, pos1+1))
        
intervals.sort()

ans = 0
prev = -10**10
for e, s in intervals:
    if s < prev:
        continue
    else:
        ans += 1
        prev = e
print(ans)
