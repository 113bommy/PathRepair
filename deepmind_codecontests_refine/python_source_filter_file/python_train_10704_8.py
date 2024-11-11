N = int(input())
S = input()
E = S.count("E")
W = 0
ans = N + 1
for s in S:
    if s == "E":
        E -= 1
    ans = min(W + E, ans)
    if s == "W":
        W -= 1
print(ans)