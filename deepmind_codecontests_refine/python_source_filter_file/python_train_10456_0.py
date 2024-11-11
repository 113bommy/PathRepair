n, m = map(int, input().split())
if n & 1: print(m)
else:
    k, t = n // 2, [int(input()[:: 2], 2) for i in range(n)]
    while True:
        if t[: k] != t[k: 2 * k][:: -1]:
            print(2 * k)
            break
        elif k & 1:
            print(k)
            break
        k //= 2