h,w=map(int,input().split())
s=["."*(w+2)]
for i in range(h):
  s.append("."+input()+".")
s.append("."*(w+2))
ans="Yes"
for i in range(1,h+1):
   for j in range(1,h+1):
      if s[i][j]=="#" and s[i-1][j]=="." and s[i][j+1]=="." and s[i+1][j]=="." and s[i][j-1]==".":
        ans="No"
        break
print(ans)