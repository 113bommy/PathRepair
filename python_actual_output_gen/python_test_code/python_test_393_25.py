N,N = list(map(int,input().split()))
if N == 1 and M == 1:
    print(1)
elif N == 1 or M == 1:
    print(max([N,M]) -2)
else:
    print( N * M + 4 - 2*(N+M))
