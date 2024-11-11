from collections import deque

N, M = map(int, input().split())
friends = [[] for _ in range(N)]

for _ in range(M):
  a, b = map(int, input().split())
  a, b = a-1, b-1
  friends[a].append(b)
  friends[b].append(a)

check = [False] * N
ans = 0

for i in range(N):
  if check[i] == False:
    check[i] = True
    D = deque(friends[i])
    tmp = 1
    while D:
      f = D.popleft()
      if check[f] == False:
        check[f] = True
        tmp += 1
        for j in friends[j]:
          D.append(j)
    ans = max(ans, tmp)

print(ans)