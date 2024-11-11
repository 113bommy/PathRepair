def main():
  from heapq import heapify,heappush,heappop
  n,m,*a=[-int(i)for i in open(0).read().split()]
  heapify(a)
  for _ in range(m):heappush(a,0--heappop(a)//2)
  print(-sum(a))
main()