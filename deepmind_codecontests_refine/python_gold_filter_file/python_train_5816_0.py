import heapq
import math
xs, ys, xt, yt = map(int, input().split())
N = int(input())

Coordinate = {-1: (xs, ys, 0), N:(xt, yt, 0)}
minRadiation = {int(i):10**20 for i in range(-1, N+1)}
ToVisit = {int(i) for i in range(-1, N+1)}
for i in range(N):
    x, y, r = map(int, input().split())
    Coordinate[i] = (x, y, r)

Q = [(0, -1)]
heapq.heapify(Q)
while Q:
    nowRadiation, index = heapq.heappop(Q)
    if index == N:
        print(nowRadiation)
        break
    elif index in ToVisit:
      ToVisit.difference_update({index})
      nowx, nowy, nowr = Coordinate[index]
      for nextIndex in ToVisit:
          nextx, nexty, nextr = Coordinate[nextIndex]
          tempTime = max(0, math.sqrt((nextx-nowx)**2 + (nexty-nowy)**2) - nowr - nextr) + nowRadiation
          if minRadiation[nextIndex] > tempTime:
              minRadiation[nextIndex] = tempTime
              heapq.heappush(Q, (tempTime, nextIndex))
