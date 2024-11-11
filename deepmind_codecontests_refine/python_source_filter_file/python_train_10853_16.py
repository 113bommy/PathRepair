import math
t=int(input())
def isPower(n):
    if (n == 0):
        return False
    while (n != 1):
        if (n % 2 != 0):
            return False
        n = n // 2

    return True
for _ in range(t):
    n=int(input())
    if n==1:
        print("FastestFinger")
    elif n==2:
        print("Ashishgup")
    else:
        if n%2!=0:
            print("Ashishgup")
        else:
           if isPower(n):
               print("FastestFinger")
           else:
               x = n // 2
               print('x,n//2', x)
               flag = 0
               for i in range(2, int(x ** (0.5)) + 1):
                   print(i)
                   if (x % i) == 0:
                       flag = 1

                       break
               if flag == 1:
                   print("Ashishgup")
               else:
                   print("FastestFinger")











