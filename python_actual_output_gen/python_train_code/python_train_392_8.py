def f(p, q):
    if p == 0 and q == 0:
        return 1
    if p == 0:
        return 0
    if q == 0:
        return 1
    #p 0 -> a
    #q -b -> b
    if (q*4 <= p):
        return 1-(q*2*q)/(2*p*q)
    else:
        return 1-(q - p/4 + q) * p /(4*p*q)

for i in range(int(input())):
    p, q = map(int, input().split(' '))
    print(f(p,q))
