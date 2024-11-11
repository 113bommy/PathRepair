import sys
H,W = map(int,input().split())
for i in range(H):
  S = list(map(str,input().split()))
  for j in range(W):
    if S[j] == "snuke":
      print(chr(65+i)+str(i+1))
      sys.exit()
    