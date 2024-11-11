Q = int(input())

for i in range(Q):
    A, B = map(int, input().split())
    A, B = min(A, B), max(A, B)

    if A == B:
        print((A - 1) + (B - 1))
        continue

    ok, ng = 0, A + B - 1
    while abs(ok - ng) > 1:
        K = (ok + ng) // 2
        m = (K + 2) // 2

        if m * (K + 2 - m) < A * B:
            ok = K
        else:
            ng = K

    print(ok)
