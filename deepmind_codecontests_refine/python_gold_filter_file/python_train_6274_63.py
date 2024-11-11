for _ in range(int(input())):
    num = int(input())
    arr = list(map(int,input().split()))
    arr.reverse()
    print(*arr)