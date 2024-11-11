s=input()
ans='No'
for i in range(len(s)-1):
  if s[i]+s[i+1]=='AC':
    ans=='Yes'
print(ans)