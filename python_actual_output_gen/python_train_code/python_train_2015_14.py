S = input()
ans = ""
for i in S:
  if i == "B":
    S = S[:-1]
  else:
    ans += i
print(ans)