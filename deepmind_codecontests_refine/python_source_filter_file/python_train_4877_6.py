#Together

N = int(input())
a = list(map(int, input().split()))

b = []

for ai in a:
    b.append(ai-1)
    b.append(ai)
    b.append(ai+1)
#print(b)

import collections
cnt = collections.Counter(b)
#print(cnt)
max(cnt.values())