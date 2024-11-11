for _ in range(int(input())):
    a,b=map(int,input().split())
    print(b-(a-1)%b-1)