for i in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    a.reverse()
    print(*a)