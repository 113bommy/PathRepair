from math import sqrt
def era(n):    
    i = 2
    limit = int(sqrt(n))
    while (i<limit):
    	if (n%i==0):
    		return True
    	i+=1
    return False
t = int(input())
for  i in range(t):
        a, b = [int(x) for x in input().split()]
        c = a+b
        z = era(c)
        if (a-b==1) and (not z):
                print("YES")
        else:
                print("NO")
