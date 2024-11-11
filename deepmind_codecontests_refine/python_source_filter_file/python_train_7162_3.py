import sys
# input = sys.stdin.readline
sys.setrecursionlimit(pow(10, 6))

xedges = [[] for _ in range(100001)]
yedges = [[] for _ in range(100001)]
xvisited = [False for _ in range(100001)]
yvisited = [False for _ in range(100001)]

def dfs(i, xy):
  if xy == 0:
    xvisited[i] = True
  else:
    yvisited[i] = True
  xc, yc, ec = (xy+1)%2, xy%2, 0
  if xy == 0:
    ec += len(xedges[i])
    for toy in xedges[i]:
      if not yvisited[toy]:
        _xc, _yc, _ec = dfs(toy, 1)
        xc += _xc
        yc += _yc
        ec += _ec
  else :
    ec += len(yedges[i])
    for tox in yedges[i]:
      if not xvisited[tox]:
        _xc, _yc, _ec = dfs(tox, 0)
        xc += _xc
        yc += _yc
        ec += _ec
  return xc, yc, ec

def main():
  n = int(input())
  for _ in range(n):
    x, y = map(int, input().split())
    xedges[x].append(y)
    yedges[y].append(x)


  ans = 0
  for i in range(1, 100001):
    if not xvisited[i] and len(xedges[i]) != 0:
      xc, yc, ec = dfs(i, 0)
      ans = xc*yc-ec//2
    elif not yvisited[i] and len(yedges[i]) != 0:
      xc, yc, ec = dfs(i, 1)
      ans = xc*yc-ec//2

  print(ans)


if __name__ == '__main__':
  main()
