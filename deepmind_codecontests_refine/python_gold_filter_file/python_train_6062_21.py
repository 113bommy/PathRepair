for _ in range(int(input())):
    n,m = map(int,input().split())
    arr = list(map(int,input().split()))
    print(min(m,sum(arr)))