import heapq

n, m = map(int, input().split())
jobs = [tuple(map(int, input().split())) for _ in range(n)]
jobs.sort()

i = 0
works = []
reward = 0
for d in range(m):
  while i < n and jobs[i][0] <= d + 1:
    heapq.heappush(works, -jobs[i][1])
    i += 1
  if works:
    reward -= heapq.heappop(words)
print(reward)