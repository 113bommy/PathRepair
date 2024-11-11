N = int(input())
S = [input().strip() for _ in range(N)]
cnt = 0
for k in range(N):
    flag = 0
    T = [S[i][k:]+S[i][:k] for i in range(N)]
    for i in range(N-1):
        for j in range(i+1,N):
            if T[i][j]!=T[j][i]:
                flag = 1
                break
        if flag==1:break
    if flag==0:
        cnt += 1
print(cnt**2)