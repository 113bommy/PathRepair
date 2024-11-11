S = input()
K = int(input())

ans = 1
for k in range(K):
  if S[k] != "1":
    ans = S[k]
    break
print(ans)