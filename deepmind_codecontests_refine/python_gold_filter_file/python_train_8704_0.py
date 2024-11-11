n=input()
k=0
if n[::-1]==n:
   k+=1
else:
   for i in range(1,len(n)):
      if n[::-1]+('0'*i)==('0'*i)+n:
         k+=1
if k>0:
   print('YES')
else:
   print('NO')