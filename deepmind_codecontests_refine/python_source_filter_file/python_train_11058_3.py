for i in range(int(input())):
    n=int(input())
    l=sorted(list(map(int,input().split())))
    print(int((l[n-1]+l[n])//4))