s=input()
k=int(input())
if len(s)==1:
  print(k//2)
  exit()
c=[]
c_=1
for i in range(1,len(s)):
  if s[i-1]==s[i]:
    c_+=1
  else:
    c.append(c_)
    c_=1
c.append(c_)
if len(c)==1:
  print((c[0]*k)//2)
elif s[0]==s[-1]:
  ans=sum([c_//2 for c_ in c[1:-1]])*k
  ans+=c[0]//2
  ans+=c[-1]//2
  ans+=((c[0]+c[-1])*(k-1))//2
  print(ans)
else:
  print(sum([c_//2 for c_ in c])*k)
#print(c)
