n, a, b, c = (int(x) for x in input().split())
d = {"A": a, "B": b, "C": c}
S = [input() for _ in range(n)]
ANS = []

for i, s in enumerate(S):
    if d[s[0]] == 0 and d[s[1]] == 0:
        print("No")
        exit()
    else:
        if d[s[0]] > d[s[1]] or (d[s[0]] == d[s[1]] == 1 and i < n - 1 and s[1] in S[i + 1]):
            d[s[1]] += 1
            d[s[0]] -= 1
            ANS.append(s[1])
        else:
            d[s[0]] += 1
            d[s[1]] -= 1
            ANS.append(s[0])
print("Yes")
for ans in ANS:
    print(ans)
