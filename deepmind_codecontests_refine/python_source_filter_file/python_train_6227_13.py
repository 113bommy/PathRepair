N, M = map(int, input().split())
A = [list(map(int, input().split())) for i in range(N)]
A=sorted(A)
sumcost = 0
for i in range(M):
    sumcost += A[0][0]
    A[0][1] -= 1
    if A[0][1] < 1:
        A.pop(0)

print(sumcost)