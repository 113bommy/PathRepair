for _ in range(int(input())):
    a = int(input())
    b = 1
    for i in range(3, a*2+1):
        b *= i
        b = b%(1e9+7)
    print(b)
