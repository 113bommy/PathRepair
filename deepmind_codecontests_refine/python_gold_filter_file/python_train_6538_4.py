#!/usr/bin/python3
# -*- coding:utf-8 -*-

from queue import deque

def main():
  h, w = map(int, input().split())
  grids = [False] * (w * h)
  dq = deque()
  for i in range(h):
    for j, c in enumerate(list(input().strip())):
      if c == '#':
        grids[i*w + j] = True
        dq.append((0, i, j))
  
  while dq:
    cnt, i, j = dq.popleft()
    for dx, dy in zip([-1, 0, 1, 0], [0, -1, 0, 1]):
      if 0 <= i+dx < h and 0 <= j+dy < w and not grids[(i+dx)*w + (j+dy)]:
        grids[(i+dx)*w + (j+dy)] = True
        dq.append((cnt+1, i+dx, j+dy))
  print(cnt)
  
if __name__=='__main__':
  main()

