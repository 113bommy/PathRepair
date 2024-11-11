for _ in range(int(input())):
    n = int(input())
    L = list(map(int,input().split()))
    print(*L[::-1])