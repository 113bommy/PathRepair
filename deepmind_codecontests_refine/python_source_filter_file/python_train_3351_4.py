I=input
for i in range(int(I())):
   a=I()
   b=I()
   n=len(a)
   c="NO"
   for i in range(n):
      if a[i]==b[i]:
         c="YES"
         break
   print(c)
      