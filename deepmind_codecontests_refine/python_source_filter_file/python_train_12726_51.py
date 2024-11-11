for i in range(int(input())):
    a, b = map(int,input().split())
    print(min((a+b),((a-1)*b)))