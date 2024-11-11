for t in range(int(input())):
    n=int(input())
    num=list(map(int,input().split()))
    print(*num[::-1])