n=int(input())
a=[]
r=[]
for i in input().split():
  a.append(int(i))
a.sort()
t=a.pop(-1)
b=a.pop(0)
for i in a:
  if i>=0:
    r.append([b,i])
    b=b-i
  else:
    r.append([t,i])
    t=t-i
print(t-b)
r.append([t,b])
for i in r:
  print(i[0],i[1])
