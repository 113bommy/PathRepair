from collections import Counter,defaultdict,deque
#alph = 'abcdefghijklmnopqrstuvwxyz'
#from math import factorial as fact
#import math

tt = 1#int(input())
#total=0
#n = int(input())

#n,m,k = [int(x) for x in input().split()]
for i in range(tt):
   n = int(input())
   s = input()
   d = defaultdict(int)
   for el in s:
      for i in range(2,int(el)+1):
         if i==9:           
            d[3]+=2
         elif i==8:
            d[2]+=3
         elif i==6:
            d[3]+=1
            d[2]+=1
         elif i==4:
            d[2]+=2
         else:
            d[i]+=1
   #print(d)
   ans =''
   while d[7]:
      ans+='7'
      d[7]-=1
      d[2]-=4
      d[3]-=2
      d[5]-=1
   while d[5]:
      ans+='5'
      d[5]-=1
      d[2]-=3
      d[3]-=1
   while d[3]:
      ans+='3'
      d[3]-=1
      d[2]-=1
   while d[2]:
      ans+='2'
      d[2]-=1
   print(ans)
      
      
      
