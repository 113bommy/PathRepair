n,x=map(int,input().split())
l=[0]
for i in range(n+1):
  l.append(2**(i+1)-1)
m=[0]
for i in range(n+1):
  m.append(2**(i+2)-3)
c=0
for i in range(n,-1,-1):
  if x<2**(i+1)-1:
    x-=1
  elif x==2**(i+1)-1:
    c+=l[i]+1
    x=0
  elif x>2**(i+1)-1:
    c+=l[i]+1
    elif x==m[i+1]:
      x-=1
    x=x-(2**(i+1)-1)
print(c)