a={chr(i) for i in range(97,123)}
s=input()
n=len(s)
if n<26:
  print(s+sorted(a-set(s))[0])
else:
  for i in range(2,27):
    if s[-i]<s[-i+1]:
      break
    if i==26:
      print(-1)
      exit()
for j in sorted(s[-i+1:]):
  if j>s[-i]:break
print(s[:-i]+j)