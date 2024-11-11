for i in range(int(input())):
    e = int(input())
    a = int("2"*(e-1)+"3")
    if e == 1:
        print(-1)
    elif a % 3 != 0:
        print(a)
    else:
        a = str(a)
        a = a.replace("2", "3", 1)
        print(a)
