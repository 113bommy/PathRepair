S = input()
T = input()
ans = float('inf')
for start in range(len(S) - len(T)):
    ans = min(ans, sum(s != t for s, t in zip(S[start:], T)))
print(ans)
