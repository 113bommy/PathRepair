import math
n = int(input())

numbers = input()
digits = []

for digit in numbers:
    if digit == '0':
        digits.append((3,1))
    else:
        digits.append((math.floor((int(digit)- 1 )/3), (int(digit) - 1) % 3))
        
l = False
r = False  
u = False
d = False

for di in digits:
    #print(str(d[0]) + "," + str(d[1]))
    if di[1] == 1 and di[0] == 3:
        l = True
        r = True
        d = True
    else:
        if di[1] == 0:
            l = True
        if di[1] == 2:
            r = True
        if di[0] == 0:
            u = True
        if di[0] == 2 and di[0] != 1:
            d = True
    
if l and r and u and d:
    print("YES")
else:
    print("NO")
