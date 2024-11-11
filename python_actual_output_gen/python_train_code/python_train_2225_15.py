S = input()
L = len(s)

ans = L
for i in range(L - 1):
    if S[i] != S[i+1]:
        ans = min(max(L - i - 1, i + 1),ans)
print(ans)
