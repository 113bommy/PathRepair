S = input()
chars = set(S)
ans = len(S)

for c in chas :
    m = max(len(_) for _ in S.split(c))
    ans = min(ans, m)

print(ans)