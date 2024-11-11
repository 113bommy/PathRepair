S = input()
ans = "CODEFESTIVAL2016"
a = 0
for i in range(S):
  if S[i] != ans[i]:
    a += 1
print(a)