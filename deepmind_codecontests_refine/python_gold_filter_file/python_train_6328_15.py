N = int(input())

c = [[0]*10 for _ in range(10)]

for k in range(1,N+1):
    c[int(str(k)[0])][int(str(k)[-1])]+=1

ans = 0

for k in range(81):
    i = k // 9 + 1
    j = k % 9 + 1
    ans += c[i][j] * c[j][i]

print(ans)

