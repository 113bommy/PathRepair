for i in range (int(input())):
    n = int(input())
    a= list(map(int,input().split()))
    k=max(a)
    a.remove(k)
    print(k+sum(a)/(n-1))