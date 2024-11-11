def d_DigitSum(N, S):
    if S == N:
        # f(b,N)=Nを満たすbはN+1が最小
        return N + 1
    if S > N:
        return -1

    from math import sqrt, floor, ceil

    def f(b, n):
        if n < b:
            return n
        else:
            return f(b, n // b) + (n % b)

    sn = ceil(sqrt(N))
    # 2<=b<=√Nまで探索
    for b in range(2, sn + 1):
        if f(b, N) == S:
            return b
    # √N<=b<=Nまで探索
    for p in range(1, sn + 1):
        if (N - S) % p == 0:
            b = (N - S) // p + 1
            if f(b, N) == S:
                return b
    return -1
N = int(input())
S = int(input())
print(d_DigitSum(N, S))