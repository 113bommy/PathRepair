import sys
readline = sys.stdin.readline
from collections import deque
T = int(readline())
Ans = []
INF = 10**9+7
for qu in range(T):
    N, M = map(int, readline().split())
    E = [[1 if s == 'a' else 0 for s in readline().strip()] for _ in range(N)]
    
    res = []
    for i in range(N):
        for j in range(N):
            if i == j:
                E[i][i] = None
            else:
                if E[i][j] == E[j][i]:
                    res = [i+1, j+1]
                    break
        else:
            continue
        break
    
    if res:
        Ans.append('YES')
        Ans.append(' '.join(map(str, (res*(M//2 + 5))[:M+1])))
    
    elif M&1:
        Ans.append('YES')
        Ans.append(' '.join(map(str, [1, 2]*(M//2 + 1))))
    elif N == 2:
        Ans.append('NO')
    else:
        Ans.append('YES')
        if E[0][1] == E[1][2]:
            x, y, z = 1, 2, 3
        elif E[1][2] == E[2][0]:
            x, y, z = 2, 3, 1
        else:
            x, y, z = 3, 1, 2
        
        ans = deque([x, y, z])
        M -= 2
        par = 0
        while M:
            M -= 2
            ans.appendleft([y, x][par])
            ans.append([y, z][par])
            par ^= 1
        Ans.append(' '.join(map(str, ans)))
                
        
print('\n'.join(Ans)) 