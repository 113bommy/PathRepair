s=input()
ans=999
for i in range(s.len()-2):
  ans=min(abs(753-int(s[i:i+2])),ans)
print(ans)