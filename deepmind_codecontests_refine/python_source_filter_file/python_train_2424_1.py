for i in range(int(input())):
    n = int(input()) // 2
    a = [int(i) for i in input().split()]
    for i in range(n):
        a[i] *= -1
    print(*a)