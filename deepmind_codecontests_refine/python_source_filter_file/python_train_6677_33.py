q = int(input())
while q > 0:
    n = input()
    list = n.split()
    n = int(list[0])
    a = int(list[1])
    b = int(list[2])
    if b >= 2*a:
        print(int(a*n))
    else:
        if n%2 == 0:
            print(int(n*b/2 + a))
        else:
            print(int(int(n/2)*b + a))
    q -= 1

