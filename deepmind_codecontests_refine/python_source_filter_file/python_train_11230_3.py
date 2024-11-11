for e in iter(input,'-1'):
 q=float(input())
 x=q/2
 while abs(x**3-q)-q*1e-5:x-=(x**3-q)/(3*x*x)
 print(x)
