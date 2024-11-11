f,l = input().split(' ')
ans = []
ans.append(f[0])
f=f[1:]
ch = l[0]
flag=0
for i in f:
  if ord(ch) <= ord(i):
    ans.append(ch)
    flag=1
    break
  else:
    ans.append(i)
if flag==0:
  ans.append(l[0])
print(''.join(map(str,ans)))