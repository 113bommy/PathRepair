n= int(input())
import math
m= math.sqrt(n)
a= set([k*(k+1)//2 for k in range(1, int(2*m))])
print(a)
for i in a:
    if n-i in a:
        print('YES')
        exit()

print('NO')