N, M = map(int, input().split())

if N==1 and M == 1:
    print(1)
if N == 1:
    print(M-N*2)
elif M == 1:
    print(N-M*2)
else:
    print(N*M-2*M-2*(N-2))