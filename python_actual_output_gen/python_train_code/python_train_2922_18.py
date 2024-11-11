import math
n = int(input())
t = 0
for i in range(n):
    s,d = map(int,input().split())
    if(t<s):
        t = s
    else:
        t = s + math.ceil((t-s)/d)*d
print(t)