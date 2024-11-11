n, a = map(int, input().split())
x = sorted(list(map(int, input().split())))
c = 0

if n == 1:
    c = 0
    
elif n == 2:
    c = min(abs(x[0] - a), abs(x[1] - a))
    
elif a <= x[0]:
    c = abs(x[n - 2] - a)
    
elif a >= x[n - 1]:
    c = abs(a - x[1])

elif a <= x[1]:
    d0 = abs(a - x[0])
    dn1 = abs(a - x[n - 1])
    dn2 = abs(a - x[n - 2])
    c = min(dn1, d0 * 2 + dn2, dn2 * 2 + d0)
    
elif a >= x[n - 2]:
    d0 = abs(a - x[0])
    d1 = abs(a - x[1])
    dn2 = abs(a - x[n - 1])
    #print(d0, d1 * 2 + dn2, dn2 * 2 + d1)
    c = min(d0, d1 * 2 + dn2, dn2 * 2 + d1)
    
else:
    d0 = abs(x[0] - a)
    d1 = abs(x[1] - a)
    dn1 = abs(x[n - 1] - a)
    dn2 = abs(x[n - 2] - a)
    c = min(d0 * 2 + dn2, d1 * 2 + dn1, dn1 * 2 + d1, dn2 * 2 + d0)
    #print(d0, d1, dn2, dn1)
    #print(d0 * 2 + dn1, d1 * 2 + dn2, dn1 * 2 + d1, dn2 * 2 + d0)
        
print(c)