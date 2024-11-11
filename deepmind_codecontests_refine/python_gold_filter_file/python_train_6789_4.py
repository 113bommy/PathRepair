for _ in range(int(input())):
    a, b = map(int, input().split())
    x = 9
    count = 0
    while x <= b:
        count+=1
        x = int(str(x) + '9')
    print(a*count)