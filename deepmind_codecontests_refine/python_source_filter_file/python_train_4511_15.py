t = int(input())
for i in range(t):
   n = int(input())
   l = list(range(1,n+1))
   for i in range(0,n-1,2):
      l[i],l[i+1] = l[i+1],l[i]
   if n%2 != 0:
      l[-1],l[-2] = l[-2],l[-1]
   print(l)