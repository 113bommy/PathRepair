from collections import deque
N = int(input())
g = [set() for i in range(N + 1)]
for i in range(N - 1):
    a, b = map(int, input().split())
    g[a].add(b)
    g[b].add(a)
    
c = list(map(int, input().split()))
c.sort(reverse=True)

print(sum(c) - c[0])

q = deque()
nums = [0] * (N + 1)

q.appendleft(1)

while q:
  d = q.popleft()
  nums[d] = c.pop(0)
  for node in g[d]:
    if nums[node] == 0:
      q.appendleft(node)
print(*nums[1:])
