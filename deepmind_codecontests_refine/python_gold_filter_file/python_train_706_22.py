def main():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    u = [1] + [0] * K
    v = [1] + [0] * K
    s = 0
    for i in A:
        u, v = v, u
        s += i
        t = 0
        for k in range(i):
            t += u[k]
            v[k] = t
        for k in range(i, min(s, K) + 1):
            t += u[k]
            v[k] = t
            t -= u[k - i]
    print(v[K] % (10 ** 9 + 7))

main()
