for _ in range(int(input())):
    n=int(input())
    per=list(map(int,input().split()))
    per.reverse()
    print(*per)