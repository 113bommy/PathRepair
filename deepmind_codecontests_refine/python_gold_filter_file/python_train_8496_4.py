import math
from operator import itemgetter
#q = int(input().strip())
q=1
while q>0:
   q-=1; days = 0
   docs = int(input())
   days = [int(x) for x in input().strip().split(' ')][0]
   for _ in range(docs-1):
       a,b = map(int, input().split(' '))
       if days < a:
           days = a
       elif days >= a:
           if not ((days-a)/b).is_integer():
                temp = int(math.ceil(math.ceil(days-a)/b))
                #print(math.ceil(math.ceil(days-a)/b))
                days = a+temp*b
           else:
               days+=b

   print(days)