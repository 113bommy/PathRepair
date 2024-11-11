n = int(input())
m = int(input())
if (n-m) >= -10:
    print(m)
else:
    print(m % 2**n)
