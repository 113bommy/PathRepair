f=False
n=(int)(input())
a=list()
a=[0]
x=[int(j) for j in input().split() if int(j)<=n ] 
for i in range(len(x)):
 a.append(x[i])
del x
for i in range(len(a)):
  l=a[i]
  m=a[l]
  n=a[m]
  if i==n :
   print("YES")
   f=True
   break
if f==False:
 print("NO")

