import sys
input = sys.stdin.buffer.readline

N,Q = map(int, input().split())
List = []
dic = {}
for _ in range(N):
    s, t, x = map(int, input().split())
    List.append((s-0.5-x, 1, x))
    List.append((t-0.5-x, -1, x))
    dic[x] = False

import heapq
    
List.sort()

h = []
j = 0
for _ in range(Q):
    D = int(input())
    while j < 2*N and List[j][0] < D:
        if List[j][1] == 1:
            heapq.heappush(h, List[j][2])
            dic[List[j][2]] = True
        else:
            dic[List[j][2]] = False
        j += 1
    while h:
        ans = h[0]
        if dic[ans]:
            print(ans)
            break
        else:
            heapq.heappop(h)
    if not h:
        print(-1)