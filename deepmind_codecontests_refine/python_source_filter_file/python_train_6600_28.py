a,b,c,d = list(map(int, input().split()))
actual,free = 0,0
if a/b < c/d:
    # frame's width becomes stretched
    free = ((b*c)-(a*d))
    actual = b*c
elif a/b > c/d:
    # frame's height becomes stretched
    free = ((a*d)-(b*c))
    actual = a*d
else:
    print(0)
    exit()
import fractions
gcd = fractions.gcd(free,actual)
print(int(free/gcd),end='')
print("/",end='')
print(int(actual/gcd),end='')


