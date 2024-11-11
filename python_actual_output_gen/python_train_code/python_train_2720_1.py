for _ in range(int(input())):
    n = int(input())
    arr = list(map(int,input().split()))
    count = 0
    matching = True
    for i in range(len(arr)):
        if arr[i]!=i+1:
            if matching:
                count+=1
            matching = False
        else:
            matching = True
    print(count)