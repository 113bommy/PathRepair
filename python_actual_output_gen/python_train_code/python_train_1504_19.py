s=int(input())-1
d=[]
while s>0:
  d.append(chr(s%26+97))
  s//=26
t=''
for i in reversed(d):
  t+=i
print(t)  