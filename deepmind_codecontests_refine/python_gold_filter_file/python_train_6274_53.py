for i in range(int(input())):
    n=int(input())
    l=[int(x) for x in input().split()]
    l2=l[::-1]
    print(*l2)