from collections import deque

N, M = map(int, input().split())
friends = [[] for _ in range(N+1)]
for __ in range(M):
  a, b = map(int, input().split())
  friends[a].append(b)
  friends[b].append(a)
checked = [0 for ___ in range(N+1)]
answer = 0
for i in range(1, N+1):
  friend = deque(friends[i])
  cnt = 0
  while(len(friend) > 0):
    f = friend.popleft()
    if checked[f] != 0:
      continue
    else:
      checked[f] = 1
      cnt += 1
      for ff in friends[f]:
        friend.append(ff)
  answer = max(answer, cnt)
print(answer)
  