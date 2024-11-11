from math import sqrt

n = int(input())

def prost(a):
    x = int(sqrt(a)+1)
    for i in range(2,x):
        if a % i == 0:
            return False
    return True

if n <= 2:
    print(1)
else:
    print(2)
    
for i in range(2,n+2):
    if i == 2 or i == 5:
        print(1, end=" ")
    elif i % 2 == 0 or i % 5 == 0: 
        print (2, end=" ") 
    elif prost(i) == True:
        print (1, end=" ")
    else:
        print (2, end=" ")