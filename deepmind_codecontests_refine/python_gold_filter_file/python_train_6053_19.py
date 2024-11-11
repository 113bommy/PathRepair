a = int(input())
b = int(input())
c = int(input())
d = int(input())

if a != d:
    print(0)
elif a == 0 and c == 0 and d == 0:
    print(1)
elif a == d  and a > 0:
    print(1)
else:
    print(0)
    