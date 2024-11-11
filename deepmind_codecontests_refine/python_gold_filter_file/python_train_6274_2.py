for _ in range(int(input())):
    n= int(input())
    arr = [int(i) for i in input().split()]
    print(*arr[::-1])