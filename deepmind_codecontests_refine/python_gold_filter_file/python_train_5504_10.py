n = int(input())

for i in range(0, n):
    a = int(input())
    b = int(input())
    if a + b >= 10 ** 80:
        print("overflow")
    elif a >= 10 ** 80:
        print("overflow")
    elif b >= 10 ** 80:
        print("overflow")
    else :
        print(a + b)