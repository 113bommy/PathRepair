import math
n=int(input())
y=1
for i in range(1,int(math.sqrt(2*n))+1):
    if 2*n-i**2-i>=0:
        if int(math.sqrt(2*n-i**2-i))*int(math.sqrt(2*n-i**2-i)+1)==2*n-i**2-i:
            print('Yes')
            y=0
            break
if y:
    print('NO')