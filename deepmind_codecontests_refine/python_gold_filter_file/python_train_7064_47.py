s=input()
ans='No'
for i in range(len(s)):
  if s[i]=='C':
    for j in s[i+1:]:
      if j=='F':
        ans='Yes'
print(ans)
