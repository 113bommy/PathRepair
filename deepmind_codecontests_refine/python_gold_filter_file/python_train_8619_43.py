import sys
input = sys.stdin.readline

from heapq import heappop, heappush

N, Q = map(int, input().split())
event_list = []
for i in range(N):
  s, t, x = map(int, input().split())
  event_list.append([s-x, 1, x])
  event_list.append([t-x, -1, x])

for i in range(Q):
  event_list.append([int(input()), 2, 0])

ans = []
event_list.sort()
x_set = set()
x_list = []
for time, event, x in event_list:
  if event == 1:
    x_set.add(x)
    heappush(x_list, x)
  elif event == -1:
    x_set.remove(x)
  else:
    while x_list and x_list[0] not in x_set:
      heappop(x_list)
    if x_list:
      ans.append(x_list[0])
    else:
      ans.append(-1)

print(*ans, sep='\n')
