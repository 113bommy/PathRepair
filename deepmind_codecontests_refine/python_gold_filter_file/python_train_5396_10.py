H,W = map(int, input().split())
S = [input() for i in range(H)]
queue = [(0,0,1)]
done ={(0,0)}
count = sum(row.count("#") for row in S)

def bfs(x,y,c):
    if(x<0 or y<0 or x>=W or y>=H or S[y][x]=="#"):
        return
    
    if(x,y) in done:
        return
    
    queue.append((x,y,c+1))
    done.add((x,y))

dx = [1,-1,0,0]
dy = [0,0,1,-1] 
flag= -1
while queue:
    x,y,c = queue.pop(0)
    if x==W-1 and y==H-1:
        flag=1
        break
    for i in range(4):
        bfs(x+dx[i],y+dy[i],c)

print(flag if flag == -1 else (H*W-count-c))