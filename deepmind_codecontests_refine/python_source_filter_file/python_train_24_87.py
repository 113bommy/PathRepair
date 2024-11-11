t = int(input())
while t > 0:
    n = int(input())
    arr = list(map(int , input().split()))
    flag = True
    sum = arr[0] + arr[1]
    for j in range(2 , n):
        if sum < arr[j]:
            flag = False
            break
    if flag == False:
        print(1,2,j+1)
    else:
        print(-1)
    t -= 1