def main():
    import sys
    input = sys.stdin.buffer.readline
    N, Q = map(int, input().split())
    *C, = map(int, input().split())

    last = [-1]*(N+1)
    P = [[] for _ in [0]*(N+1)]
    for i, c in enumerate(C):
        if last[c] != -1:
            P[last[c]].append(i+1)
        last[c] = i+1

    queries = [[] for _ in [0]*(N+1)]
    indices = [[] for _ in [0]*(N+1)]
    for i in range(Q):
        l, r = map(int, input().split())
        queries[l].append(r)
        indices[l].append(i)

    def add(A, i, x):
        while i <= N:
            A[i] += x
            i += i & -i

    def sum(A, i):
        ret = 0
        while i:
            ret += A[i]
            i ^= i & -i
        return ret

    A = [0]*(N+1)
    ans = [0]*Q
    for l in range(N, 0, -1):
        for cr in P[l]:
            add(A, cr, 1)
        for i, r in zip(queries[i], queries[l]):
            ans[i] = r-l+1-sum(A, r)

    print(*ans, sep='\n')


if __name__ == '__main__':
    main()
