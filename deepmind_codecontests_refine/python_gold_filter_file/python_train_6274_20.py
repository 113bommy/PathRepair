for test in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))
    print(*l[::-1])