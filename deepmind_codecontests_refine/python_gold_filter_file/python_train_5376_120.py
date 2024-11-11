n = int(input())
m = int(input())
if (n > 30):
    print(m)
else:
    print(m % (1 << n))