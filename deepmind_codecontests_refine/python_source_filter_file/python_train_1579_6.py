n = int(input())
a = input().count("1")
b = n - a
if a == 0:
    print("2 " * n)
elif b == 0:
    print("1 " * n)
elif a == 1:
    print("2 1 " + "2 " * (n - 2))
elif a == 2:
    print("1 " + "2 " * (n - 2) + "1 ")
else:
    print("1 1 1 " + "2 " * b + "1 " * (a - 3))