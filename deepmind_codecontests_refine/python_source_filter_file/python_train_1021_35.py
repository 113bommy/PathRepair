H,W=map(int,input().split())
S=[input() for _ in range(H)]
ans='Yes'
for i in range (H):
  for j in range (W):
    if S[i][j]=='#':
      if S[max(0,i-1)][j]!='#' and S[min(i+1,W-1)][j]!='#' and S[i][max(0,j-1)]!='#' and S[i-1][min(j+1,H-1)]!='#':
        ans='No'
        break
print(ans)