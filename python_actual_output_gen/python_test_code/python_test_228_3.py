for _ in range(int(input())):
    arr1 =  [int(i) for i in input().split()]
    if arr1[1]-arr1[0]==0:
        print(0)
    elif abs(arr1[1]-arr1[0])%10==0:
        print((arr1[1]-arr1[0])//10)
    else:
        print((abs((arr1[1]-arr1[0]))//10)+1)