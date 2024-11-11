n,m=input().split()
i=1
l=list()
d=list()
for i in range(int(n)):
   x=input()
   l=x[1:].split()
   for v in l:
      if v not in d:
         d.append(v)
      else:
         continue
count=0
for i in range(int(m)):
   for k in d:
      if i+1 ==int(k):
         count=count+1

      else:
         continue

if count==int(m):
   print('YES')
else:
   print('NO')