test = int(input())
for i in range(test):
    n = int(input())
    arr = list(map(int,input().split()))
    rakh = [0] * n
    temp = False
    for i in range(0,n-1):
        value = (arr[i] + i + 1000000000) % n
        if rakh[value] != 0:
            temp = True
            break
        else:
            rakh[value] = 1
    if temp == True:
        print("No\n")
    else:
        print("Yes\n")