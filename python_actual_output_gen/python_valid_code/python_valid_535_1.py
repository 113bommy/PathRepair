for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    if a[-1] == 0:
        for i in range(1, n+1):
            print(i, end=' ')
        print(n+1)
    else:
        temp = a.index(1)+1
        for i in range(1, temp):
            print(i, end=' ')
        print(n+1, end=' ')
        for i in range(temp, n):
            print(i, end=' ')
        print(n+1)