from math import gcd
for i in range(int(input())):
         ang = int(input())
         if ang == gcd(ang,180):
               print(360 // gcd(ang,180))
         else:
               print(180 // gcd(ang,180))