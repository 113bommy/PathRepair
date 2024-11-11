import sys
from heapq import heappush, heappop
input = sys.stdin.readline
data = []
n,q = map(int,input().split())
for i in range(n):
    s, t, x = map(int, input().split())
    data.append([s-x,t-x,x])
data.sort(key=lambda x:x[0])
d_index = 0
candidate_x = []
inf = float("inf")
data += [[inf,inf,inf]]
for i in range(q):
    d = int(input())
    while d >= data[d_index][0]:
        heappush(candidate_x, (data[d_index][2], data[d_index][1]))
        d_index += 1
    if len(candidate_x) == 0:
        print(-1)
    else:
        while candidate_x:
            x,finish_t = heappop(candidate_x)
            if finish_t > d:
                heappush(candidate_x, (x, finish_t))
                print(x)
                break
        else:
            print(-1)



