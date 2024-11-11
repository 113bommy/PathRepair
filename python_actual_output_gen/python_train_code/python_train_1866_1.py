n  = int(input())
m = int(input())

if n >= 24:
    print(m)
else:
    print(m % (1 << n))