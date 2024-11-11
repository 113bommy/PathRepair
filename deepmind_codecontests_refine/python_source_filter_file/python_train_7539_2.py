int_inp   = lambda: int(input()) #integer input
strng     = lambda: input().strip() #string input
strl      = lambda: list(input().strip())#list of strings as input
mul       = lambda: map(int,input().split())#multiple integers as inpnut
mulf      = lambda: map(float,input().split())#multiple floats as ipnut
seq       = lambda: list(map(int,input().split()))#list of integers
import math
from collections import Counter,defaultdict

a = list(input())
b = list(input())
x =set(a)
y = set(b)
if 1-x.issubset(y):
    print(-1)
    exit()
d  = dict.fromkeys(b,0)
d1 = dict.fromkeys(b,0)
for i in range(max(len(a),len(b))):
    try:
        d[a[i]]+=1
    except:
        pass
    try:
        d1[b[i]]+=1
    except:
        pass
ans = 0
for i,j in zip(d.values(),d1.values()):
    ans += min(i,j)
print(ans)
