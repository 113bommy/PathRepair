a, b = [int(x) for x in input().split()]

if b > a:
    a, b = b, a
    
r = 0
while b:
    r += a // b
    a %= b
    a, b = b, a    
    #print(a, b)

print(r) 