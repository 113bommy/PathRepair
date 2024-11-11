s=input()
t=input()
a=-1
c=0
if not set(t)<=set(s):print(-1);exit()
for i in t:
  a=s.find(i,a+1)
  if a==-1:
    c+=1
    a=s.find(i)
print(c*len(s)+a+1)