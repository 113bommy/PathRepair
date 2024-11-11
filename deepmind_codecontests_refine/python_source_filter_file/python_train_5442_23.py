import math
for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input()))
    if len(a) == 1:
        if a[0]%2 == 0:
            print(2)
        else:
            print(1)
    else:
        r,b = 0,0
        for i in range(n):
            if (i+1)%2 == 0 and a[i]%2 ==0:
                b += 1
            elif (i+1)%2 == 1 and a[i]%2 == 1:
                r += 1

        if n%2 == 0:
            if b>1:
                print(2)
            else:
                print(1)
        else:
            if r>1:
                print(1)
            else:
                print(2)
        
 
