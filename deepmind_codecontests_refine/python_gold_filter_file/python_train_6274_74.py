for _ in range(int(input())):
    n=int(input())
    x=[int(x) for x in input().split()]
    print(*x[::-1])
    