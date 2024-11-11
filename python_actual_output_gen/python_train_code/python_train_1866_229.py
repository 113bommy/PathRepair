n = int(input())
m = int(input())
if n > 23:
    print(0)
else:
    s = m % 2 ** n
    print(s)
