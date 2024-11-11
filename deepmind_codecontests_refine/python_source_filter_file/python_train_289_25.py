S=input()
ans="No"
for i in range(8):
  T=S[:i]+S[len(S)-(7-i):]
  if T=='keyence':
    ans="Yes"
    break
print(ans)