for _ in range(int(input())):
   n=int(input())
   L=list(map(int,input().split()))
   c=1
   for i in range(len(L)):
      for j in range(i+1,len(L)):
         if abs(L[i]-L[j])==1:
            c=c+1
   if c%2==0:
      print(2)
   else:
      print(1)