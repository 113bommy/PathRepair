for i in range(int(input())):
    n=int(input())
    lst=list(map(int,input().split()))
    s=list(set(lst))
    print(*s)