for i in range(int(input())):
    n = int(input())
    arr = list(map(int,input().split()))
    
    if sum(arr)%2 == 0:
        print("0")
    else:
        print("1")