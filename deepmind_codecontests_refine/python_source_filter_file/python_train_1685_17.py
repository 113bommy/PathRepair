for _ in range(int(input())):
    n = int(input())
    price = list(map(int,input().split()))
    arr = [0]*n
    arr[-1] = price[-1]
    for i in range(n-2,-1,-1):
        arr[i] = min(price[i],arr[i+1])
    res = 0
    res = sum([1 for i,val in enumerate(price) if val>=arr[i]])
    print(res)