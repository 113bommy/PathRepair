from collections import deque
from math import ceil,floor,sqrt,gcd
def ii(): return int(input())
def mi(): return map(int,input().split())
def li(): return list(mi())
def si():return input()
r,g,b=mi()
ans=0
r1,g1,b1=r,g,b
ans+=r//3
ans+=g//3
ans+=b//3
r%=3
g%=3
b%=3
if(r*g*b==8):
    ans+=2
elif((r*g==4 and b1>=3) or ( g*b==4 and r1>=3) or (g>=3 and r*b==4)):
    ans+=1
else:
    ans+=min(min(r,g),b)
print(ans)