for _ in range(int(input())):
    # n = int(input())
    n, m = list(map(int, input().split())) 
    # arr = list(map(int, input().split()))
    # arr2 = list(map(int, input().split()))
    # string = list(input())
    # ans = []
    temp = n*m
    ans = temp//2
    if n % 2 == 1:
        ans += 1
    print(ans)
