S = input()

ans = len(S)
for i in range(1, len(S)):
    if S[i-1] != S[i]:
        ans = min(ans, max(i, len(S)-i))

print(ans)
