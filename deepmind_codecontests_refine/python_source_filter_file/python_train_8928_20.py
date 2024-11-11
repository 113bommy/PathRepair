from collections import deque

def main():
  H,W,K=map(int,input().split())
  x1,y1,x2,y2 = map(lambda x: int(x)-1,input().split())
  S=[list(input()) for _ in range(H)]
  INF = 10**20

  def bfs(x0,y0,x_goal,y_goal):
    seen = [[0 for i in range(W)] for j in range(H)]
    d = [[INF for i in range(W)] for j in range(H)]
    d[x0][y0] = 0
    todo = deque()
    seen[x0][y0] = 1
    todo.append((x0,y0))
    while todo:
      x0,y0 = todo.popleft()
      dx,dy = (1,-1,0,0),(0,0,1,-1)
      for i in range(4):
        for k in range(K):
          x,y = x0+dx[i]*(k+1), y0+dy[i]*(k+1)
          if x<0 or x>=H:break
          if y<0 or y>=W:break
          if d[x][y] < d[x0][y0] + 1: break
          if S[x][y]=='@':break
          if seen[x][y] = 1: continue
          seen[x][y] = 1
          todo.append((x,y))
          d[x][y] = d[x0][y0] + 1
          if x==x_goal and y == y_goal: return d[x][y]
    return d[x_goal][y_goal]

  ans = bfs(x1,y1,x2,y2)
  print(ans if ans < INF else -1)
  
if __name__ == "__main__":
  main()