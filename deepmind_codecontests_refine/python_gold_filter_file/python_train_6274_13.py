for _ in range(int(input())):
    a=int(input())
    b=[int(x) for x in input().split()]
    b.reverse()
    print(*b)