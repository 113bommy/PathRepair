n = int(input())
m = int(input())

if n > 300:
    print(m)
else:
    x = m % 2**n
    print(x)