for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    top = max(a)
    ave = (sum(a)-top)/(n-1)
    print((ave+top)/2)