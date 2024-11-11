import math
t = int(input())
while t>0:
   t-= 1
   s = input()
   s = sorted(list(map(int,s.split())))
   s = s[0]+s[1]+s[2]
   #print(s)
   print((int(s))//2)