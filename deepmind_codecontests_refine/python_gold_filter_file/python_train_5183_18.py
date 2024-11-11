N = int(input())
A = list(map(int,input().split()))

DP = [0,0,0]
m = N//2*2
if N%2 == 0:
    for i in range(0,m,2):
        DP[0] += A[i]
        DP[1] += A[i+1]
        DP[1] = max(DP[0],DP[1])

    print(DP[1])

else:
    for i in range(0,m,2):
        DP[0] += A[i]
        DP[1] += A[i+1]
        DP[2] += A[i+2]

        DP[1] = max(DP[0],DP[1])
        DP[2] = max(DP[1],DP[2])

    print(DP[2])
