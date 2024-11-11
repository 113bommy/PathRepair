s=input()
a=[]
b=[]
d=0
for i in range(int(input())):
  q=input()
  if q=="1":d^=1
  else:
    _,f,c=q.split()
    f=int(f)-1
    if d==0:
      if f==0:a.append(c)
      else:b.append(c)
    else:
      if f==1:a.append(c)
      else:b.append(c)
if d==0:print("".join(a)[::-1]+s+"".join(b))
else:print("".join(b)[::-1]+s[::-1]+"".join(a))
