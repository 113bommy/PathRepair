n=int(input())
a=input().split()
for i in range(n):
  a[i]=int(a[i])
a.sort()
#print(a)
k=0
h=a[0]
for i in a:
  if(i==h):
    if(k==1):
      k=0
    else:
      k=1
  else:
    if(k==1):
      p=1
      break
    k=1
  h=i  
if(k==1):
  print("Conan")
else:
  print("Agasa")