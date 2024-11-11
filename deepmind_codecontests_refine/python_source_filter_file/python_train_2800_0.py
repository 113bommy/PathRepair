def main():
  n, k = map(int, input().split())
  
  plst = []
  xlst = []
  ylst = []
  dlst = []
  
  for i in range(n):
    x1,y1,d1,x2,y2,d2 = map(int, input().split())
    plst.append((x1,y1,d1,x2,y2,d2))
    xlst.append(x1)
    xlst.append(x2)
    ylst.append(y1)
    ylst.append(y2)
    dlst.append(d1)
    dlst.append(d2)
  
  xlst = list(set(xlst))
  ylst = list(set(ylst))
  dlst = list(set(dlst))
  
  xlst.sort()
  ylst.sort()
  dlst.sort()
  
  xdic = {}
  ydic = {}
  ddic = {}
  
  for i, v in enumerate(xlst):
    xdic[v] = i
  for i, v in enumerate(ylst):
    ydic[v] = i
  for i, v in enumerate(dlst):
    ddic[v] = i
  
  new_map = [[[0] * len(dlst) for _ in ylst] for _ in xlst]
  
  for p in plst:
    x1, y1, d1, x2, y2, d2 = p
    x1, y1, d1, x2, y2, d2 = xdic[x1], ydic[y1], ddic[d1], xdic[x2], ydic[y2], ddic[d2]
    for x in range(x1, x2):
      for y in range(y1, y2):
        for d in range(d1, d2):
          new_map[x][y][d] += 1
  
  ans = 0
  for i in range(len(xlst) - 1):
    xlsti = xlst[i]
    xlsti1 = xlst[i - 1]
    x = xdic[xlsti]
    for j in range(len(ylst) - 1):
      ylstj = ylst[j]
      ylstj1 = ylst[j - 1]
      y = ydic[ylstj]
      for z in range(len(dlst) - 1):
        dlstz = dlst[z]
        dlstz1 = dlst[z - 1]
        d = ddic[dlstz]
        if new_map[x][y][d] >= k:
          ans += (xlsti1 - xlsti) * (ylstj1 - ylstj) * (dlstz1 - dlstz)
  print(ans)

main()
