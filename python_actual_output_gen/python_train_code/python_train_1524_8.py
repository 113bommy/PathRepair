for i in range(int(input())):
    a=int(input())
    b=list(map(int,input().split()))
    if len(set(b))==a:
        print(a)
    else:
        print(1)