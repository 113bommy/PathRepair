import sys
from collections import deque
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)

N = int(input())
S = []
for i in range(N):
    s = list(input().strip())
    s_list = [int(k) for k in s]
    S.append(s_list)

count_max = 0
for i in range(N):
    flag = [-1]*N
    q = deque([i])
    flag[i] = 0
    count = 0
    while(q):
        count += 1
        for k in range(len(q)):
            v = q.popleft()
            for j in range(len(S[v])):
                if S[v][j] == 1 and flag[j] == -1:
                    flag[j] = count
                    q.append(j)
                elif S[v][j] == 1:
                    if flag[j]%2 != count%2:
                        print(-1)
                        sys.exit()
    count_max = max(count, count_max)
print(count_max)
        
