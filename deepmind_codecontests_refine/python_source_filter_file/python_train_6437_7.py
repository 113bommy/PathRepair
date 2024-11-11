S = input()
best = len(S)
for i in range(1, len(S)):
    if S[i-1] != S[i]:
        best = min(best, max(i, len(S) - 1))
print(best)