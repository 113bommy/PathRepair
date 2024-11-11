for _ in range(int(input())):
    n=int(input())
    l=[int(x) for x in input().split()]
    l=l[::-1]
    print(*l,sep="")