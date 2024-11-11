for i in range(int(input())):
    a, b = map(int, input().split())
    l = list(map(int, input().split()))
    if a == 2:
        print(-1)
    elif a >= 3:
        if b < a:
            print(-1)
            continue
        elif a == b:
            print(2*sum(l))
            for c in range(1, a):
                print(i, i+1)
            print(a, 1)