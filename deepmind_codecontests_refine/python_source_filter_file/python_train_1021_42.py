h,w = map(int,input().split())
s = [list("."+input()+".") for _ in range(h)]
s=["."*(w+2)]+s+["."*(w+2)]
flg = 0
for i in range(h):
  for j in range(w):
    if s[i][j] == "#":
      if s[i-1][j]=="." and s[i+1][j]=="." and s[i][j-1]=="." and s[i][j+1]==".":
        flg = 0
print("Yes" if flg == 0 else "No")
    