import random

s = input()
a = list()
for items in s:
    a.append(items)

if int(a[6])%2 == 0:
   print('1')
else:
   print('0')