from collections import deque
def main():
  h,w=map(int,input().split())
  ans,q=0,deque()
  visited=[[0 if j=="#" else -1 for j in input()] for _ in range(h)]
  q=deque([(i,j) for i in range(h) for j in range(w) if visited[i][j]==0])
  while q:
    x,y=q.popleft()
    for i,j in ((0,1),(1,0),(-1,0),(0,-1)):
      newx,newy=x+i,y+j
      if 0<=newx<h and 0<=newy<w:
        if visited[newx][newy]==-1:
          visited[newx][newy]=visited[x][y]+1
          q.append((newx,newy))
          ans=max(ans,visited[newx][newy])
  return print(ans)
if __name__=='__main__':
  main()
