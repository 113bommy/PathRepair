def distance_from(x, N, adj):
    ret = [-1] * N
    ret[x] = 0
    q = [x]
    while len(q):
        cur = q.pop()
        for nxt in adj[cur]:
            if ret[nxt] != -1:
                continue
            ret[nxt] = ret[cur] + 1
            q.append(nxt)
    return ret


def main():
    N = int(input())
    adj = [set() for _ in range(N)]
    for _ in range(N-1):
        a, b = map(int, input().split())
        adj[a-1].add(b-1)
        adj[b-1].add(a-1)
    dist = distance_from(0, N, adj)
    idx = 0
    for i in range(N):
        if dist[i] > dist[idx]:
            idx = i
    diameter = max(distance_from(idx, N, adj))
    if diameter % 3 == 1:
        print("Second")
    else:
        print("First")


if __name__ == "__main__":
    main()
