n = int(input())
m = int(input())
if n > 32:
    print(m)
else:
    print(m % (2 ** n))