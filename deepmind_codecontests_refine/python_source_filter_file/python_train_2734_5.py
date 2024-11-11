queries = int(input())

for i in range(queries):
    
    n = int(input())
    
    arr = [int(x) for x in input().split()]
    arr.sort()
    flag = True
    
    for i in range(1,n):
        if arr[i]-arr[i-1] > 1:
            flag = False
            break
            
    print(["YES","NO"][flag])