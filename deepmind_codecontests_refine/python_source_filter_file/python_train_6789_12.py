for i in range(int(input())):
    x, y = map(int, input().split())
    print(x*(len(str(y))-1))