H, W = map(int, input().split())
S = [[""]]*H
for i in range(H):
  S[i] = input()
print(S)

dh = [-1,-1,-1,0,0,1,1,1]
dw = [-1,0,1,-1,1,-1,0,1]

for i in range(H):
  for j in range(W):
    count=0
    if S[i][j]==".":
      for l in range(8):
        if H>i+dh[l]>-1 and W>j+dw[l]>-1:
          if S[i+dh[l]][j+dw[l]]=="#":
            count+=1
      S[i]=S[i][:j] + str(count) + S[i][j+1:]

for i in range(H):
  print(S[i])