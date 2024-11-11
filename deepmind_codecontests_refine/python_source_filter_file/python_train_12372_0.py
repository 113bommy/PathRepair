N = int(input())
A = [list(map(int, input().split())) for i in range(N)]
ans = 0
for i in range(N-1):
    for j in range(i+1, N):
        direct = A[i][j]
        for k in range(N):
            if k == i or k == j:
                continue
            ind = A[i][k] + A[k][j]
            if direct > ind:
                print(-1)
                exit()
            elif direct == ind:
                break
        else:
            ans += direct
print(ans)