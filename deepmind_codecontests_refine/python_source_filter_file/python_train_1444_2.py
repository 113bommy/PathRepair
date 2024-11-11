def sol():
    N = int(input())
    S = int(input())

    if N == S:
        print(N + 1)
        return

    def digitSum(n, b):
        if b < 2:
            return -1
        if n < b:
            return n
        return digitSum(n // b, b) + n % b

    for b in range(2, int(N**0.5) + 1):
        if digitSum(N, b) == S:
            print(b)
            return

    for p in range(1, int(N**0.5) + 1):
        b = (N - S) // p + 1
        if digitSum(N, b) == S:
            print(b)
            return
    print('-1')

sol()