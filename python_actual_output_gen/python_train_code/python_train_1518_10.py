s=input()
h=list(map(str,input().split()))
c=0
for i in range(len(h)):
  if s[0] in h[i]:
    c=c+1
  if s[1] in h[i]:
    c=c+1
if c>0:
  print('YES')
else:
  print('N0')