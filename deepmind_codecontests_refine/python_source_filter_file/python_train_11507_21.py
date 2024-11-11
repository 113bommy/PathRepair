import math
n=int(input())
s=math.factorial(n)/(math.factorial(n-5)*math.factorial(5))
s1=math.factorial(n)/(math.factorial(n-6)*math.factorial(6))
s2=math.factorial(n)/(math.factorial(n-7)*math.factorial(7))
print(int(s1+s2+s))