import sys


def input():
    return sys.stdin.readline().strip()


def bellman_ford(edges, N, start):
    dist = [float("inf") for _ in range(N)]
    dist[start] = 0
    # 辺の情報を見ることを1ループとすると
    # 1回のループで,最低でも1つの頂点について，スタートからの最短距離が求まる
    # つまり,スタートからの全ての頂点への距離は，
    # スタートを除いた頂点の数である,(N-1)回のループで求まる．
    for i in range(2 * N):
        for fro, to, cost in edges:
            if dist[to] > dist[fro] - cost:
                dist[to] = dist[fro] - cost
                # N回目に頂点の更新があると，負の経路がある
                if i == N - 1:
                    dist[to] = -float("inf")

    return dist


def main():
    N, M, P = map(int, input().split())
    edge = []
    for _ in range(M):
        A, B, C = map(int, input().split())
        edge.append((A - 1, B - 1, C - P))
    dist = bellman_ford(edge, N, 0)

    if dist[-1] == -float("inf"):
        print(-1)
    else:
        if dist[-1] > 0:
            print(0)
        else:
            print(-1 * dist[-1])


if __name__ == "__main__":
    main()
