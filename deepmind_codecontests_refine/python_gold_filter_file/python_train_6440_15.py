n,a,b=map(int,input().split())
s=input()
pa,pb=0,0
for i in range(n):
  if s[i]=='a':
    if pa+pb<a+b:
      pa+=1
      print('Yes')
    else:
      print('No')
  elif s[i]=='b':
    if pa+pb<a+b and pb<b:
      pb+=1
      print('Yes')
    else:
      print('No')
  else:
    print('No')
