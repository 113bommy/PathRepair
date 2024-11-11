import bisect
def main():
    N, K = map(int, input().split())
    V = list(map(int, input().split()))
    m = 0
    for i in range(min(N, K)+1):
        for j in range(min(K - i, N-i)):
            t = V[:i] + V[N-j:]
            t.sort()
            ind = bisect.bisect_right(t, 0)
            d = min((i+j), K - i - j, ind)
            m = max(m, sum(t[d:]))
    print(m)
main()
