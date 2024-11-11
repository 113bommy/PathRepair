import heapq 
n = int(input())
An = list(map(int, input().split()))
former = An[:n]
latter = An[2*n:]
latter = list(map(lambda x:-x, latter))
heapq.heapify(former)
heapq.heapify(latter)

sum_former = sum(former)
sum_latter = sum(latter)

former_list = [0]*(n+1) 
latter_list = [0]*(n+1) 
former_list[0] = sum_former 
latter_list[0] = sum_latter 

for i in range(n, 2*n):
  heapq.heappush(former, An[i])
  m = heapq.heappop(former)
  former_list[i-n+1] = former_list[i-n] + An[i] - m 

for i in range(2*n-1, n-1, -1):
  heapq.heappush(latter, -An[i])
  m = heapq.heappop(latter)
  latter_list[2*n-i] = latter_list[2*n-i-1] - An[i] - m

latter_list.reverse()
ans = -float('inf')
for i in range(n):
  ans = max(ans, former_list[i]+latter_list[i])
print(ans)