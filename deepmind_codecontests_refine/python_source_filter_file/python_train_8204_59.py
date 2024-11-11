N = int(input())
S = input()

ans = 0
for i in range(N):
    ans = max(ans,len(set(s[:i]) & set(s[i:]))
print(ans)