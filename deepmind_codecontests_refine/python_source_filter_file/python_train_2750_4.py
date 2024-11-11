for ctr in range(1):
    n=int(input())
    a=list(map(int,input().split()))
    k=[a.count(i) for i in a]
    print(max(k),end=" ")
    print(len(k))
