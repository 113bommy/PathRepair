n = int(input())
m = int(input())
if n > 23:
    print(m)
else:
    s = m % 2 ** n
    print(s)
