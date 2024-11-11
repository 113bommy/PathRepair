for _ in range(int(input())):
    n=int(input())
    a=[*map(int,input().split())]
    ans=a.sort(reverse=True)
    print(ans)