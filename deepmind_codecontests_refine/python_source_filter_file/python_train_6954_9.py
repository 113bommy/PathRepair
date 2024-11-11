H, W = map(int, input().split())
S = [input() for _ in range(H)]
 
up =    [[0]*(W+2) for _ in range(H+2)]
down =  [[0]*(W+2) for _ in range(H+2)]
left =  [[0]*(W+2) for _ in range(H+2)]
right = [[0]*(W+2) for _ in range(H+2)]

for i in range(1, H+1):
    for j in range(1, W+1):
        if S[i-1][j-1] == '.':
            up[i][j] = up[i-1][j] + 1
            left[i][j] = left[i][j-1] + 1
        
        if S[-i][-j] == '.':
            down[-1-i][-1-j] = down[-i][-1-j] + 1
            right[-1-i][-1-j] = right[-1-i][-j] + 1

ans = 0
for i in range(1, H+1):
    for j in range(1, W+1):
        ans = max(ans, up[i][j]+down[i][j]+left[i][j]+right[i][j]-3)
print(ans)