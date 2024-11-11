def main():
  import sys
  from heapq import heappush, heappop, heapify
  input = sys.stdin.readline
  
  N,D,A = map(int,input().split())
  hq = []
  for i in range(N):
    x,h = map(int,input().split())
    hq.append((x,0,h))
  heapify(hq)

  ans = 0
  b = 0
  while(len(hq) > 0):
    x,a,h = heappop(hq)
    if a == 0:
      if b < h:
        cnt = ((h-b)+A-1)//A
        ans += cnt
        b += A*cnt
        heappush(hq, (x+2*D,1,A*cnt))
    else:
      b -= h
  
  print(ans)

if __name__ == '__main__':
  main()