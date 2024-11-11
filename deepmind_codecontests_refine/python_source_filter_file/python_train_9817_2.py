"""
  Author: Enivar
  Date:  
"""

from sys import exit, stderr, stdout

vector = lambda lim, fill: [fill for _ in range(lim)] 
def debug(*args):
   for i in args: 
      stderr.write(str(i)+' ')
   stderr.write('\n')


class Input:
   def __init__(self):
      self.i = 0

   def inp(self, x):
      return x


for _ in range(int(input())):
   c1, c2, c3 = map(int, input().split())
   c = [c1,c2,c3]
   a = [int(x) for x in input().split()]
   fg = False
   for i in range(3):
      if a[i]>c[i]:
         print('NO')
         fg = True
         break
   if fg: continue

   if a[3]: 
      ppw = min(c1-a[0], a[3])
      a[0]+=ppw
      a[3]-=ppw
   if a[4]:
      plw = min(c2-a[1], a[4])
      a[1]+=plw
      a[4]-=plw

   if sum(a[2:])>c3: print('N0')
   else: print('YES')












   
