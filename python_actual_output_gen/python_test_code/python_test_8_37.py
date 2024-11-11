for _ in range(int(input())):
    s, a, b, c = map(int, input().split())
    print(b * (s//c)//a + s//c)