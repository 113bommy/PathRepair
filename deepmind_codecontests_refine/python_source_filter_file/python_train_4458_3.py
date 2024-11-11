a=0
for i in range(int(input())):
  b=input().split()
  if b[1]=='JPY':
    a+=int(b[0])
  else:
    a+=int(b[0])*380000
print(a)