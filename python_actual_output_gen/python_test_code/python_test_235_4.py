a, m = map(int, input().split())
x = 0
while a % m != 0:
    a += a % m
    x+=1
    if x >= m**0.1:
        break
if a % m == 0:
    print('Yes')
else:
    print('No')