for t in range (int(input())):
    n=int(input())
    arr=list(map(int,input().split()))
    arr.reverse()
    print(*arr,sep=" ")