a,b,c = list(map(int,input().split()))
r = 0
q = 0
a, b = sorted([a, b])
a1 = a
b1 = b
while a1 != c+1 or b1 != c+1:
    q = b1 % a1
    if q == 0:
        r += 1 
    b1 += b
    if a1 > c or b1 > c:
        break
if b > c:
    print(0)
else:
    print(r)