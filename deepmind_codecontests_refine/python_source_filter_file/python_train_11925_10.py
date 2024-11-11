from itertools import permutations
import math, sys

inp = input().split()

n = int(inp[0]) - 1
m = int(inp[1]) - 1
na = []
ma = []
ln = 0
lm = 0

while(n > 0):
    na.append(n % 7)
    n //= 7
    ln += 1
while(m > 0):
    ma.append(m % 7)
    m //= 7
    lm += 1
na.reverse()
ma.reverse()

cnt = ln + lm
if(cnt > 7 or cnt < 2):
    print(0)
    sys.exit();
if(ln == 0):
    na.append(0)
if(lm == 0):
    ma.append(0)
ln = max(1, ln)
lm = max(1, lm)
perm = permutations([x for x in range(0, 7)], ln + lm)
ex = 0
ex2 = 0
ans = 0
t1 = 0
t2 = 0
#print(ln, lm)
#print(na, ma)
for i in perm:
    ex = 2
    ex2 = 2
    #print(i)
    s = "";
    for k in range(0, ln) :
        t1 = int(na[k])
        t2 = int(i[k])
        if(t1 > t2):
            ex = 1
            break
        if(t1 < t2):
            ex = 0
            break
    if(ex == 2 and t1 == t2):
        ex = 1    
    for k in range(0, lm) :
        t1 = int(ma[k])
        t2 = int(i[ln + k])
        if(t1 > t2):
            ex2 = 1
            break
        if(t1 < t2):
            ex = 0
            break
    if(ex2 == 2 and t1 == t2):
        ex2 = 1
    #print(ex, ex2, i)
    if(ex == 1 and ex2 == 1):
        ans += 1
        
print(ans)
    



    
