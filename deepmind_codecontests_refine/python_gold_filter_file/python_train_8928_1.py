from collections import deque
import sys

N_MAX = 200000 + 5

H, W, K = map(int, input().split())
sth, stw, glh, glw = map(int, input().split())

INF = 10**6 * K

dp = [[INF for _ in range(W+2)] for _ in range(H+2)]

dp[0] = [-1]*(W+2)
dp[H+1] = [-1]*(W+2)
for h in range(1, H+1):
    s = sys.stdin.readline()
    dp[h][0] = -1
    dp[h][W+1] = -1
    for w in range(1, W+1):
        if s[w-1] == "@":
            dp[h][w] = -1

dp[sth][stw] = 0


# Seen = [[INF]*W for _ in range(H)]
XY = {(1, 0), (-1, 0), (0, 1), (0, -1)}


def bfs(sth, stw, glh, glw):
    next_q = deque()
    next_q.append((sth, stw))

    while len(next_q) != 0:
        # キュー取り出し(先頭)
        h, w = next_q.popleft()
        for dh, dw in XY:
            for sk in range(1, K+1):
                hs, ws = h + dh*sk, w + dw*sk
                if dp[hs][ws] == -1:
                    break
                if dp[hs][ws] == INF:
                    next_q.append((hs, ws))
                    dp[hs][ws] = dp[h][w] + 1
                elif dp[hs][ws] <= dp[h][w]:
                    break
                if hs == glh and ws == glw:
                    return dp[h][w] + 1
    return -1


def main():
    ret = bfs(sth, stw, glh, glw)
    print(ret)


if __name__ == '__main__':
    main()
