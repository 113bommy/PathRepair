for _ in range(int(input())):
    n = int(input())
    l = list(map(int,input().split()))
    f = 0
    for i in range(len(l)):
        if l[i] % 2 == 0:
            print(1)
            print(i+1)
            f = 1
            break

        if i == 2:
            f = 2
            break

    if f == 1:
        continue

    if f == 2:
        print(2)
        print(1,2)
        continue

    if f == 0:
        print(-1)
        break