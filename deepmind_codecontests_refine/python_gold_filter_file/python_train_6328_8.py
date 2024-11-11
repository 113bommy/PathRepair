N = int(input())

C = [[0]*10 for _ in range(10)]
for n in range(1, N+1):
    s = str(n)
    C[int(s[0])][int(s[-1])] += 1

ans = 0
for i in range(10):
    for j in range(10):
        ans += C[i][j]*C[j][i]
print(ans)
