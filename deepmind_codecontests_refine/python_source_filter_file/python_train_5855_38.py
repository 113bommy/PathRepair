n = int(input() ) 
 
def func(x):
    a, b = 1000000, 100000000
    for i in range(1, x):
        if(x % i == 0):
            if(abs((x / i) - i) < a):
                a, b = abs((x / i) - i), i
    return b
                    
if(func(n) == 1):
    print("1" + str(n))
else:
    print(str(func(n) ) + str(n / func(n)))