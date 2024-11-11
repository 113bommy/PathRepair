n = int(input())

for i in range(0, n):
    a = int(input())
    b = int(input())
    if len(str(a + b)) > 80:
        print("overflow")
    elif len(str(a)) > 80:
        print("overflow")
    elif len(str(b)) > 80:
        print("overflow")
    else :
        print(a + b)