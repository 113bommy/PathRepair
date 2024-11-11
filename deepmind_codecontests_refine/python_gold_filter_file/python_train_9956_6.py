from decimal import * 
a,b,c=[int(i)for i in input().split()]
getcontext().prec = 1000
x = Decimal(a)
y = Decimal(b)
s=str(x/y)
if len(s) >1000 :h = s[2:-1].find(str(c))
else : h = s[2:].find(str(c))
if c == 0 and h == -1 and len(s)<1000:print(len(s)-1)
else : print(  h + 1 if h != -1 else -1)