n = int(input())
a = int(input())
b = int(input())
c = int(input())
kefir = 0
if n < a and n < b:
    print(0)
elif b - c >= a:
    print(n // a)
else:
    kefir += ((n-c)//(b-c))
    n -= ((n-c)//(b-c)) * (b-c)
    kefir += (n//a)
    print(kefir)