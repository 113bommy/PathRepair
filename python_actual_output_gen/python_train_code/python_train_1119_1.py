S = input()
n = len(S)
maze = [1] * n
# 前から見る
for i in range(0,n-1):
    if S[i] == S[i+1] == 'R':
        print('before',maze)
        maze[i+2] += maze[i]
        maze[i] = 0
        print('after',maze)
# 後ろから見る
for i in range(n-1,0,-1):
    if S[i] == S[i-1] == 'L':
        maze[i-2] += maze[i]
        maze[i] = 0
# 答え
print(*maze)
