end = [1,1,1,1,1]
while True:
  n = int(input())
  if n == 0:
    break
  mp = [[0] * 5 for _ in range(6000)]
  height = [0] * 5
  cnt = 0
  for i in range(n):
    d, p, q = map(int, input().split())
    q -= 1
    cnt += p
    if d == 1:
      pos = max(height[q:q + p])
      mp[pos][q:q + p] = [1] * p
      if mp[pos] == end:
        cnt -= 5
        mp.pop(pos)
        mp.append([0] * 5)
        for x in range(5):
          for y in range(i * 5 - 1, -1, -1):
            if mp[y][x] == 1:
              height[x] = y + 1
              break
          else:
            height[x] = 0
      else:
        height[q:q + p] = [pos + 1] * p

    if d == 2:
      pop_flag = False
      pos = height[q]
      for y in range(pos, pos + p):
        mp[y][q] = 1
      for y in range(pos + p - 1, pos - 1, -1):
        if mp[y] == end:
          cnt -= 5
          mp.pop(y)
          mp.append([0] * 5)
          pop_flag = True
      
      if pop_flag:
        for x in range(5):
          for y in range(i * 5 - 1, -1, -1):
            if mp[y][x] == 1:
              height[x] = y + 1
              break
          else:
            height[x] = 0
      else:
        height[q] += p
  
  print(cnt)
