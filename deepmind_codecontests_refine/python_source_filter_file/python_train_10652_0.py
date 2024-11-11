t = int(input())
for i in range(0,t):
   s = list(input())
   s = [ord(s[j])-96 for j in range(0,len(s))]
   # s.sort()
   n = len(s)
   if 1 not in s:
      print("NO")
      continue
   l=s.index(1)-1
   r = s.index(1)+1
   k=2
   f=1
   # print(s)
   while(l>=0 and r<n):
      if s[l]==k:
         l-=1
         k+=1
      elif s[r]==k:
         r+=1
         k+=1
      else:
         f=0
         break

   while(l>=0 and f==1):
      if s[l]==k:
         l-=1
         k+=1
      else:
         f=0
         break

   while(r<n and f==1):
      if s[l]==k:
         r+=1
         k+=1
      else:
         f=0
         break

   if f==1:
      print("YES")
   else:
      print("NO")
