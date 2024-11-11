N = int(input())
S = input()
ans = 0
for a in range(1, N):
    cnt = 0
    for i in range(N - a):
        if S[i + a] == S[i]:
            cnt += 1
        else:
            cnt = 0
        ans = max(ans, min(cnt, N - a - 1))
print(ans)
