N = int(input())
S = input()
ans = 0
for i in range(1, N):
    cnt = 0
    for j in range(N-i):
        if S[j] == S[i+j]:
            cnt += 1
            if cnt == i:
                ans = max(ans, i)
                break
        else:
            ans = max(ans, cnt)
            cnt = 0
    ans = max(ans, cnt)
print(ans)
