N = int(input())
A = [tuple(map(int, input().split())) for _ in range(N)]
B = A[:]
A.sort(key=lambda x: x[0])
B.sort(key=lambda x: x[1])

if N%2:
    print(B[N//2][1] - A[N//2][0] + 1)
else:
    print((A[N//2][1] + B[N//2-1][1]) - (B[N//2][0] + A[N//2-1][0])+1)