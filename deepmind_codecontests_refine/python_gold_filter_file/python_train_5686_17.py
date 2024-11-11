n=int(input())
a=[list(map(int,input().split())) for i in range(n)]
a.sort()
p = -1
q = -1
f = 0
for l,r in a:
   if l>p:
      p = r
   elif l>q:
      q = r
   else:
      f = 1
      break
if f:
   print("NO")
else:
   print("YES")