T = int(input())
for i in range(T):
    n, A, B, C, D = map(int, input().split())
    memo = {}
    
    def herasu(N):
        if N == 0:
            return 0
        if N == 1:
            return D
        if N in memo:
            return memo[N]
        m = 100000000000000000000000
        if N % 2 == 0:
            m = min([m, A + herasu(N//2)])
        else:
            m = min([m, A + herasu(N//2) + D])
            m = min([m, A + herasu(N//2 + 1) + D])
        if N % 3 == 0:
            m = min(m, B + herasu(N//3))
        else:
            m = min([m, B + herasu(N//3) + (B%3) * D])
            m = min([m, B + herasu(N//3 + 1) + (3-(B%3)) * D])
        if N % 5 == 0:
            m = min(m, C + herasu(N // 5))
        else:
            m = min([m, C + herasu(N//5) + (B%5) * D])
            m = min([m, C + herasu(N//5 + 1) + (5-(B%5)) * D])
        m = min([m, D * N])
        memo[N] = m
        return m

    print(herasu(n))
