for _ in range(int(input())):
   n = int(input())
   d = str(input())
   if n==1:
      if int(d)%2==0: print(2)
      else: print(1)
      continue
  
   Raze = []
   Breach = []
   m_r = []
   m_b = []
   for i in range(n):
      if i%2==0:
         Raze.append(int(d[i]))
         if int(d[i])%2==0: m_r.append(0)
         else: m_r.append(1)
      else: 
         Breach.append(int(d[i]))
         if int(d[i])%2==0: m_b.append(0)
         else: m_b.append(1)

   b = m_b.count(0)
   r = m_r.count(1)
   if b>0 and n%2==0: print(2)
   elif r==0 and b==0: 
      if n%2==1: print(2)
      else: print(1)
   else: 
      if b>r and n%2==1: print(2)
      else: print(1)
