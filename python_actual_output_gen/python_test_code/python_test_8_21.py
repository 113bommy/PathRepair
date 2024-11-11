for _ in range(int(input())):
    s, a, b, c = map(int,input().split())
    t = int(s/c)
    p = int(s/a)
    t += p*b
    print(t)
