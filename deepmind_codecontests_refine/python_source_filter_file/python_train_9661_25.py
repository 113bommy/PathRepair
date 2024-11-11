import collections

def solve():
  n = int(input())
  a = collections.deque(sorted(list(int(i) for i in input().split())))
  big = a.pop()
  mini = a.popleft()
  queue = collections.deque([])
  #print(big,mini)
  while (a):
    if a[0] <= 0:
      tmp = a.popleft()
      queue.append((big,tmp))
      big -= tmp
    else:
      tmp = a.pop()
      queue.append((tmp,mini))
      mini -= tmp
  print(big-mini)
  queue.append((big,mini))
  for i in range(len(queue)):
    print(*queue[i])
  
solve()
