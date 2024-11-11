from math import factorial
s=input()
s1=input()
plus=s.count('+')-s1.count('+')
minus=s.count('-')-s1.count('-')
n=s1.count('?')
if plus<0 and minus<0:
    print(0)
else:
    print((factorial(n)/factorial(n-plus)/factorial(plus))*(0.5**2))