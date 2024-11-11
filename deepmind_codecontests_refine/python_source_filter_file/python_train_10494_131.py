n,a,b,c,d=map(int,input().split())
s=input()
f=0;F=0
for i in range(a,max(c,d)-1):
  if s[i]=='#' and s[i+1]=='#':f=1
for i in range(b-2,d-1):
  if s[i]=='.' and s[i+1]=='.' and s[i+2]=='.':F=1
if F==0 and c>d:f=1
print('YNeos'[f::2])