import math
n  = int(input())
l = int(input())
count = 0 
while l>=n:
    l//=n
    count+=1
if n==l:
    print('YES')
    print(count)
else:
    print('NO')