def main():
    N, M = map(int, input().split())
    A = sorted(list(map(int, input().split())), reverse=True)
    def helper(x):
        p = len(A) - 1
        t = 0
        for a in A:
            while p >= 0 and A[p] + a < x:
                p -= 1
            t += p + 1
        return t
    l, r = 0, A[0] * 2 + 1
    while r - l > 1:
        m = (l + r) // 2
        if helper(m) > M:
            l = m
        else:
            r = m
    k = sum(A)
    p = len(A) - 1
    t = (M - helper(l)) * l
    for a in A:
        while p >= 0 and A[p] + a < l:
            k -= A[p]
            p -= 1
        t += a * (p + 1) + k
    print(t)

main()
