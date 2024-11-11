s=int(input())
ans='Good'
for i in range(3):
  if s[i]==s[i+1]:
    ans='Bad'
print(ans)