import heapq

n = int(input())
alist = list(map(int, input().split()))

ante, post = alist[:n], alist[-n:]
antesums = [0 for _ in range(n+1)]
postsums = [0 for _ in range(n+1)]
antesums[0] = sum(ante)
postsums[0] = sum(post)
post = list(map(lambda x: -x, post))
heapq.heapify(ante)
heapq.heapify(post)

for k in range(n):
  minante = heapq.heappushpop(ante, alist[n+k])
  antesums[k+1] = antesums[k] + alist[n+k] - minante
  maxpost = heapq.heappushpop(post, -alist[2*n-k-1])
  postsums[k+1] = postsums[k] + alist[2*n-k-1] + maxpost

ans = -sum(alist)
for k in range(n+1):
  if ans < antesums[k] - postsums[-k]:
    ans = antesums[k] - postsums[-k-1]
print(ans)
