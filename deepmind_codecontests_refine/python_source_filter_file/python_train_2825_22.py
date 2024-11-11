from collections import Counter, defaultdict

BS="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
def to_base(s, b):
    res = ""
    while s:
        res+=BS[s%b]
        s//= b
    return res[::-1] or "0"
alpha = "abcdefghijklmnopqrstuvwxyz"
from math import floor, ceil






n = int(input())
flag = False

for b in range(100000):
    a = (n-(7*b))/4
    if int(a)==float(a) and 4*a+7*b==n and a >= 0 and b >= 0:
        #print(a,b)
        print(str("4")*int(a), end="")
        print(str("7")*b)
        flag = True
        break
if not flag:
    print(-1)