#!/usr/bin/env python3
import sys
from collections import deque

def solve(N: int, S: "List[str]"):
    matrix = [[] for _ in range(N)]
    d = [[10**9]*N for _ in range(N)]

    for i in range(N):
        d[i][i] = 0
        for j in range(N):
            if S[i][j] == "1":
                matrix[i].append(j)
                d[i][j] = 1
                d[j][i] = 1
    
    # ２部グラフ 判定
    stack = [(0,1)]
    color = [-1]*N

    while stack:
        node,c = stack.pop()
        color[node] = c

        for next in matrix[node]:
            if color[next] == -1:
                stack.append((next,~c))
            else:
                if c^color[next] == 0:
                    print(-1)
                    return


    for k in range(N):
        for i in range(N):
            for j in range(N):
                d[i][j] = min(d[i][j], d[i][k] + d[k][j])

    answer = 0
    for i in range(N):
        answer = max(answer,max(d[i]))
    print(answer+1)
    return

def main():
    N = int(input())
    S = [input() for _ in range(N)]
    solve(N, S)

if __name__ == '__main__':
    main()
