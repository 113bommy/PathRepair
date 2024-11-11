for _ in range(int(input())):
    a = int(input())
    b = int(input())
    s = a + b
    if s >= 1e79:
        print('overflow')
    else:
        print(s)