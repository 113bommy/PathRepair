N, M = map(int,input().split())

if N == 1 or M == 1:
    if N + M == 1:
        print(1)
    else:
        print(N*M-2)
else:
    print((N-2)*(M-2))
