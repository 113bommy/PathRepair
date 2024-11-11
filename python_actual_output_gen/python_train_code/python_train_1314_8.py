import math
def Prime(x):
    if x<2:
        return False
    for i in range(2,int(math.sqrt(x))+1):
        if x%i==0:
            return False
    return True
n=int(input())
if Prime(n):
    print(1)
elif n%2==0:
    print(2)
elif Prime(n-1):
    print(2)
else:
    print(3)