for i in range (int(input())):
    t = int(input())
    a= list(map(int,input().split()))
    k=max(a)
    a.remove(k)
    print(k+sum(a)/(k-1))