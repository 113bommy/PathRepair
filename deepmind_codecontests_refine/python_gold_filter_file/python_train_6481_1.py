for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    x = 0
    for i in range(n):
        if a[i] == 1:
            x += 1
        else:
            break
    if x == 0:
        print('First')
    else:
        if a[i] != 1:
            if x % 2 == 0:
                print('First')
            else:
                print('Second')
        else:
            if x % 2 == 1:
                print('First')
            else:
                print('Second')
