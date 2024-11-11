x,k,d = map(int, input().split())
x = abs(x)

walk = min(x,x//d)
k -= walk
x -= walk*d

if k%2 == 0:
    print(x)
else:
    print(d-x)
