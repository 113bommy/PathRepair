from math import*
n,m,t = map(int,input().split())
summ = 0
if (m+n==t):
    print('1')
elif (m == 1):
    z = 1
    a = t - m
    while(z>0):
        x = int(factorial(n)/(factorial(a)*factorial(n-a)))
        y = int(factorial(m)/(factorial(t-a)*factorial(m-(t-a))))
        summ = int(summ + x*y)
        a = a+1
        z = int(z - 1)
    print(summ)
    
elif (n == 4):
    z = 1
    a = t - n
    while(z>0):
        x = int(factorial(m)/(factorial(a)*factorial(m-a)))
        y = int(factorial(n)/(factorial(t-a)*factorial(n-(t-a))))
        summ = int(summ + x*y)
        a = a+1
        z = int(z - 1)
    print(summ)
    
elif (t-m>=4 and t-n>1):
    z = (m+n-t)+1
    a = t - m
    while(z>0):
        x = int(factorial(n)/(factorial(a)*factorial(n-a)))
        y = int(factorial(m)/(factorial(t-a)*factorial(m-(t-a))))
        summ = int(summ + x*y)
        a = a+1
        z = int(z - 1)
    print(summ)
elif (t-m<4 and t-n<=1):
    z = t-4
    a = 4
    while(z>0):
        x = int(factorial(n)/(factorial(a)*factorial(n-a)))
        y = int(factorial(m)/(factorial(t-a)*factorial(m-(t-a))))
        summ = int(summ + x*y)
        a = a+1
        z = int(z - 1)
    print(summ)

elif (t-m>4 and t-n<1):
    z = (m-1)+1
    a = 1
    while(z>0):
        x = int(factorial(m)/(factorial(a)*factorial(m-a)))
        y = int(factorial(n)/(factorial(t-a)*factorial(n-(t-a))))
        summ = int(summ + x*y)
        a = a+1
        z = int(z - 1)
    print(summ)

elif (t-m<4 and t-n>1):
    z = (n-4)+1
    a = 4
    while(z>0):
        x = int(factorial(n)/(factorial(a)*factorial(n-a)))
        y = int(factorial(m)/(factorial(t-a)*factorial(m-(t-a))))
        summ = int(summ + x*y)
        a = a+1
        z = int(z - 1)
    print(summ)

