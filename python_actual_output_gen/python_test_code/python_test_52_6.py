for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split(" ")))
    high = 0
    low = 0
    for i in range(n-1,1,-1):
        if(a[i-1] < a[i]):
            high = i
            break
    for j in range(high,1,-1):
        if(a[j-1] > a[j]):
            low = j
            break
    print(low)