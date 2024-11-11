def f():
    a = int(input())
    if a == 1 or a == 2:
        print("-1");return
    elif a % 2 == 0:
        b = (a*a)/4 -1
        c = (a*a)/4 +1
    else:
        b = (a*a + 1)/2
        c = (a*a - 1)/2
    print(int(b),int(c))
f()