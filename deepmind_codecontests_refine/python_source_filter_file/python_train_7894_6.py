N, M = map(int, input().split())
# N, M = 100000, 100000

mod = 10 ** 9 + 7
if N < M:
    N, M = M, N

if M - N >= 2:
    print(0)
elif M - N == 1:
    prod = 1
    for i in range(1, N + 1):
        prod = (prod * i) % mod
    print((prod * prod * M) % mod)
else:
    prod = 1
    for i in range(1, N + 1):
        prod = (prod * i) % mod
    print((2 * prod * prod) % mod)
