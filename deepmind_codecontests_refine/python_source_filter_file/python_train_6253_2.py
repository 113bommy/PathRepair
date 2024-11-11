V, E, r = map(int, input().split())

INF = 2 << 21
G = [[] for i in range(V)]
dist = [INF for j in range(V)]


def bellman_ford(s):
    p, flg = [-1 for i in range(V)], [False for i in range(V)]
    dist[s], flg[s], cnt = 0, True, 0

    while True:
        if cnt >= V:
            return False

        on = []
        for i in range(V):
            if flg[i]:
                on.append(i)
                flg[i] = False

        if len(on) == 0:
            return True

        for i in on:
            for j in G[i]:
                if dist[i] + j[1] < dist[j[0]]:
                    dist[j[0]] = dist[i] + j[1]
                    p[j[0]], flg[j[0]] = i, True

        cnt += 1


def main():
    for i in range(E):
        s, t, d = map(int, input().split())
        G[s].append((t, d))

    check = bellman_ford(r)

    if check:
        for i in range(V):
            if dist[i] == INF:
                print("INF")
            else:
                print(dist[i])
    else:
        print("NEGATIVE CYCLE")


if __name__ == '__main__':
    main()

