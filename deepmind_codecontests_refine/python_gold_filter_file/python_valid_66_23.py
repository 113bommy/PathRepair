for q in range(int(input())):
 k=int(input())
 i=0
 while k>0:
  k-=1
  i+=1
  while i%3==0 or i%10==3:
   i+=1
 print(i)