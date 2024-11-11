ans=0
for _ in range(int(input())):
  ans+=eval("-"+input().replace(" ","+"))+1
print(ans)