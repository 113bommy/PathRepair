N, M = map(int, input().split(" "))

if M > N:
    tmp = N
    M = N
    N = tmp

if N == 1 and M == 1: print(1)
elif M == 1: print(N-2)
else: print((N-2)*(M-2))