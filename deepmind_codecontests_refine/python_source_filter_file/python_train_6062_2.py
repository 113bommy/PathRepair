for _ in range(int(input())):
    n,m = map(int,input().split())
    arr = list(map(int,input().split()))
    print(max(m,sum(arr)))