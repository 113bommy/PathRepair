n=int(input())
a=input()
a=a.split()
for i in range(2*n):
   a[i]=int(a[i])
a.sort()
b=[]
c=[]
for i in range(n):
   b.append(a[i])
for i in range(n):
   c.append(a[i+n])

j="YES"
for i in range(n):
   if b[i]>=c[i]:
      j="NO"
print(j)
