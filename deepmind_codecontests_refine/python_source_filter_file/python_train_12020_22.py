import math
n, m, a, b = list(map(int, input().split()))
if (b / m) > a:
    print(n*a)

elif (b / m) < a and b < a * n and math.ceil(n/m)*b > ((n%m)*a + (n//m)*b):
    print((n%m)*a + (n//m)*b)

elif (math.ceil(n/m))*b < ((n%m)*a + (n//m)*b):
    print(math.ceil(n/m)*b)
    
elif (b / m) < a and b > a * n:
    print(n*a)


else:
    print(n*a)

    
    

    
    
    
    
    
