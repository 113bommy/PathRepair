n=int(input())
ans=0
a=0;b=0;ab=0
for i in range(n):
  s=input()
  ans+=s.count("AB")
  if s[0]=="B":
    b+=1
    if s[-1]=="A":
      ab+=1
      b-=1
  elif s[-1]=="A":
    a+=1
if a+b==0:
    print(ans+ab-1)
else:
    print(ans+min(a,b)+ab)
