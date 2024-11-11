for _ in range(int(input())):
    n = int(input())
    x = list(map(int, input().split()))

    print(sum(x) + n - x.count(0) - (x[-1] > 0))