a = float(input())
b = float(input())
#if a>b: a,b=b,a
ansa = (a+b)/2
ta = abs(a-ansa)
if ansa<0: ansa+=360.0

ansb = (a+b-360)/2
tb = abs(a-ansb)
if ansb<0: ansb+=360.0

if ta<tb: print(ansa)
else: print(ansb)