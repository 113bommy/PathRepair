import math
n  = int(input())
l = int(input())
count = 0 
while n>l:
    n//=l
    count+=1
if n==l:
    print('YES')
    print(count)
else:
    print('NO')