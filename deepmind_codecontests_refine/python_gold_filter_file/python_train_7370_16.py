import collections
import sys

N = int(input())
xy = [list(map(int,input().split())) for i in range(N)]

if N == 1:
    print(1)
    sys.exit()

pq = []
for i in range(N):
    for j in range(N):
        if i != j:
            pq.append((xy[i][0]-xy[j][0], xy[i][1]-xy[j][1]))
#print(pq)
pqc = collections.Counter(pq)
x = pqc.most_common()[0][1]
print(N-x)
