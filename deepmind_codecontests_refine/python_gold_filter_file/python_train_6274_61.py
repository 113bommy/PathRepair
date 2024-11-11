for i in range(int(input())):
    n=int(input())
    lst=list(map(int,input().split()))
    print(*lst[::-1])