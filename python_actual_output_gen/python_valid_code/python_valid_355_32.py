for t in range (int(input())):
    n=int(input())
    l1=list(map(int,input().split()))
    l1.sort(reverse=True)
    print(l1)