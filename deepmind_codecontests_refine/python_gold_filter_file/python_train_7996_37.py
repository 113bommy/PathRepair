S = str(input())
K = int(input())
for i in range(K):
  if S[i] != "1":
    print(S[i])
    break
else:
  print(1)