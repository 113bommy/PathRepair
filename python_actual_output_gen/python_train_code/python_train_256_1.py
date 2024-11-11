N = int(input())
A = list(map(int, input().split()))

cntA = 0
cntB = 0
for i in range(N):
    if A[i]%4 == 0:
        cntA += 1
    elif A[i]%2 == 0:
        cntB += 1

print("Yes" if cntA*2 + cntB >= N else "No")