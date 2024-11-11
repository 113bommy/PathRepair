for _ in range(int(input())):
    x = int(input())
    a = [int(t) for t in input().split()]
    print(*a[::-1])
