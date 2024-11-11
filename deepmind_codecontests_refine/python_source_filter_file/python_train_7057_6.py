import sys
s=input()
k=int(input())

s_2=s*2
pre=""
ans=0

if s.count(s[0])==len(s):
  print((len(s)*k)//2)
  sys.exit()

for i in range(len(s)):
  if pre==s[i]:
    ans+=1
    pre=""
  else:
    pre=s[i]

pre=""
ans1=0
for i in range(len(s_2)):
  if pre==s_2[i]:
    ans1+=1
    pre=""
  else:
    pre=s_2[i]

if 2*ans<ans1:
  print(ans+(k-1)*ans1)
else:
  print(ans*k)
