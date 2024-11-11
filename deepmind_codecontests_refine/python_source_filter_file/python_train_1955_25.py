from decimal import Decimal
n = int(input())
a = []
r = {}
for i in range(n):
    d = int(float(input())*10**9+0.0001)
    d2 = 0
    d5 = 0
    while True:
        if d % 2 != 0 and d % 5 != 0:
            break
        if d % 2 == 0:
            d //= 2
            d2 += 1
        if d % 5 == 0:
            d //= 5
            d5 += 1
    a.append((d2,d5))
    r[(d2,d5)] = r.get((d2,d5),0) + 1
ans = 0
for x , y in r.keys():
    for i , j in r.keys():
        if min(x+i,y+j) >= 18:
            ans += r[(x,y)]*r[(i,j)]
            if x == i and y == j:
                ans -= r[(x,y)]
                
print(ans//2)