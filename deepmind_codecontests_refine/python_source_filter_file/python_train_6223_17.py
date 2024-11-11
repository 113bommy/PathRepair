S = input()
T = input()
ans = len(T)
for i in range(len(S) - len(T)):
    ans = min(ans, sum([1 for j in range(len(T)) if T[j] != S[i + j]]))
print(ans)
