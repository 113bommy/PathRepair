a=1
b=0
s=0
z=[1]
for n in range(int(input())):
  s=a+b
  n=a
  a=s
  b=n
  z.append(s)
d=''
for n in range(1,len(z)):
  if n in z:
    d+='O'
  else:
    d+='o'
print(d)