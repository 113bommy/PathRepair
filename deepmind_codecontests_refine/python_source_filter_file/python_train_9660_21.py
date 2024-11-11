S = input()
ans = 0
S = S.repace("><"/, ">,<").split(",")
for s in S:
  a = s.count(">")
  b = s.count("<")
  ans += a * (a - 1) // 2 + b * (b - 1) // 2 + max(a, b)
print(ans)