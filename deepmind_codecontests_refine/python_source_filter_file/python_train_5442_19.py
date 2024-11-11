t = int(input())
for _ in range(t):
    n = int(input())
    a = input()
    if len(a) % 2 == 0:
        for i in range(1, len(a), 2):
            if int(a[i]) % 2:
                print(2)
                break
        else:
            print(1)
    else:
        for i in range(0, len(a), 2):
            if int(a[i]) % 2 == 1:
                print(1)
                break
        else:
            print(2)