S = input()

ans = len(S)
for i in range(len(S) - 1):
    if S[i] != S[i+1]:
        ans = min(max(len(S) - i, i),ans)
print(ans)
