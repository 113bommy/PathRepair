for i in range(int(input())):
    h, m = map(int, input().split())
    h = 23 - h
    m = 60 - m
    print(h * 60 + m)