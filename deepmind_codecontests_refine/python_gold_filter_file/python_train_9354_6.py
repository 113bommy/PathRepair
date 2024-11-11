H, W = map(int, input().split())
alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
S = [list(map(str, input().split())) for _ in range(H)]
for i in range(H):
  for j in range(W):
    if S[i][j] == "snuke":
      print("{}{}".format(alpha[j], i+1))
