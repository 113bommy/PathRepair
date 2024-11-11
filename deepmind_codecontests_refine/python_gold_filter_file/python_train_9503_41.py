from math import factorial
n=int(input())
x=(factorial(n)/((factorial(n//2)**2)*2))
y=(factorial((n//2)-1)/2)**2
#print(x,y)
print(int(x*y*4))
