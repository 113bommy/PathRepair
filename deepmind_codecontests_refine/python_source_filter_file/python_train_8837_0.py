from heapq import heappop as pop
from heapq import heappush as push
INF = 10 ** 20

def main():
  n, k = map(int, input().split())
  
  clst = []
  rlst = []
  
  for i in range(n):
    c, r = map(int, input().split())
    clst.append(c)
    rlst.append(r)
  
  edges = [[] * n for i in range(n)]
  
  for i in range(k):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    edges[a].append(b)
    edges[b].append(a)
  
  costs = [INF for i in range(n)]
  costs[0] = 0
  used = [False for i in range(n)]
  
  def make_to_lst(s_num):
    loop = rlst[s_num]
    temp = {i for i in edges[s_num]}
    ret = {i for i in temp}
    while loop:
      new = set()
      for p in temp:
        pto = {i for i in edges[p]}
        new = new | pto
      ret = ret | temp
      temp = new - ret
      if not temp:
        break
      loop -= 1
    return ret
  
  used[0] = True
  costs[0] = 0
  break_flag = 0
  que = [(clst[0], 0)]
  
  while que and not break_flag:
    next_cost, s_num = pop(que)
    to_lst = make_to_lst(s_num)

    for num in to_lst:
      costs[num] = next_cost
      if num == n - 1:
        break_flag = 1
        break
      if not used[num]:
        push(que, (costs[num] + clst[num], num))
        used[num] = True
  
  print(costs[num - 1])

main()
