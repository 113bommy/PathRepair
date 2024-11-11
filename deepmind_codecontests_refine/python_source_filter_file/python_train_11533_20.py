from collections import deque

h,w = map(int,input().split())
ch,cw = map(int,input().split())
dh,dw = map(int,input().split())
S = ["#" *(w+2) ] + ["#" + input()+ "#" for _ in range(h)] + ["#" *(w+2) ]
v = [[10 ** 6]*(h+2) for _ in range(w+2)]
v[ch][cw] = 0
Q = deque([(ch,cw)])
while Q :
    y,x = Q.popleft()

    for i,j in [(0,1),(1,0),(-1,0),(0,-1)] :
        if S[y+i][x+j] == "." and v[y+i][x+j] > v[y][x]:
            v[y+i][x+j] = v[y][x]
            Q.append((y+i,x+j))
    for i in range(-2,3) :
        for j in range(-2,3) :
            if i == j == 0 :
                continue
            elif 1 <= y+i <= h and 1 <= x+j <= w and S[y+i][x+j] == "." and v[y+i][x+j] > v[y][x] + 1 :
                v[y+i][x+j] = v[y][x] + 1
                Q.appendleft((y+i,x+j))
ans = v[dh][dw]
if ans == 10 ** 6 :
    print(-1)
else :
    print(ans)