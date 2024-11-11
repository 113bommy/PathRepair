for _ in range(int(input())):
    l1, r1, l2, r2 = map(int, input().split())
    if l1 != r2:
        a = l1
        b = r2
    else:
        a = r1
        b = l2
    
    print(a, b)
