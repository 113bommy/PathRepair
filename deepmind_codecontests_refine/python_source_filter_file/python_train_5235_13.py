for _ in range(int(input())):
    n, k = map(int, input().split())
    res = sorted(map(int,input().split()))
    print(res[-1:-k])