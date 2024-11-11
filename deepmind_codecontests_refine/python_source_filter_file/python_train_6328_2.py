N = int(input())

A = [[0]*10 for i in range(10)]

for i in range(1, N+1):
    A[int(str(i)[0])][int(str(i)[-1])] = 1

ans = 0
for i in range(10):
    for j in range(10):
        ans += A[i][j] * A[j][i] 

print(ans)