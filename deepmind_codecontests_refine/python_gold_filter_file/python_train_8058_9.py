# You lost the game.
n, m = map(int, input().split())
A = list(map(int, input().split()))
L = [int(input()) for _ in range(m)]
T = [0 for _ in range(n)]
T[n-1] = 1
R = [0 for _ in range(10**5+1)]
R[A[n-1]] = 1
for i in range(n-2,-1,-1):
    if R[A[i]]:
        T[i] = T[i+1]
    else:
        T[i] = T[i+1]+1
        R[A[i]] = 1
for i in range(m):
    print(T[L[i]-1])
