N = int(input())
S = input()

ans = 0
for i in range(N):
    ans = max(ans,len(set(S[:i]) & set(S[i:])))

print(ans)