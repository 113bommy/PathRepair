from heapq import *

m, t, r = map(int, input().split())
w = list(map(int, input().split()))
ws = set()

for wi in w:
    ws.add(wi)
    ws.add(wi+1)

w = list(ws)
w.sort()
s = set()
pq = []

for wi in w:
    while pq:
        if pq[0]<wi:
            heappop(pq)
        else:
            break
        
    for i in range(max(0, r-len(pq))):
        if t>=i and wi-1-i not in s:
            s.add(wi-1-i)
            heappush(pq, wi-i+t)
        else:
            print(-1)
            exit()

print(len(s))