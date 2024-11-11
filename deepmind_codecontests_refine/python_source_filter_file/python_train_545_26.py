N = int(input())
A = list(map(int, input().split()))

if N == 1:
    print(1, 1)
    print(-A[0])
    print(1, 1)
    print(0)
    print(1, 1)
    print(0)
else:
    print(1, 1)
    print(-A[0])
    print(2, N)
    for a in A[1:]:
        print((a - N) * (N - 1), end=' ')
    print()
    print(1, N)
    print(0, end=' ')
    for a in A[1:]:
        print((a - N + 1) * N, end=' ')
