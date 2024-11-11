for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split(' ')))
    print(max(arr) + (sum(arr) - max(arr))/(n-1))