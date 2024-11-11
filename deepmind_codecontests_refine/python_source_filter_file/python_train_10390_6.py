from bisect import bisect_left, bisect_right


def main():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    idx = [[] for _ in range(int(2e5+1))]
    for i in range(N):
        idx[A[i]].append(i)
    pos = 0
    empty = []
    visited = set()
    while pos == 0 or pos % N != 0:
        empty.append(pos)
        visited.add(pos % N)
        a = A[pos % N]
        nxt = bisect_right(idx[a], pos % N) % len(idx[a])
        npos = idx[a][nxt] + (pos//N) * N
        if npos <= pos:
            npos += N
        pos = npos + 1
    goal = N * K % pos
    cur = empty[max(0, bisect_right(empty, goal) - 1)]
    #print(cur, goal)
    ans = []
    seen = set()
    while cur < goal:
        i = cur % N
        a = A[i]
        nxt = bisect_right(idx[a], cur % N) % len(idx[a])
        ncur = idx[a][nxt] + (cur//N) * N
        if ncur <= cur:
            ncur += N
        if ncur <= goal:
            cur = ncur + 1
        else:
            ans += [a]
            cur = cur + 1
    print(*ans)


if __name__ == "__main__":
    main()
