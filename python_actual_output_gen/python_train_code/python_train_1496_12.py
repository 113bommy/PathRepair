
n = int(input())
lis = list(map(int,input().split()))
if(n < 3):
    print("no")
else:
    flag = 0
    for i in range(1,n):
        if(lis[i-1] > lis[i]):
            r = lis[i-1]
            l = lis[i]
        else:
            l = lis[i-1]
            r = lis[i]
        for j in range(i+1,n):
            if(lis[j-1] > lis[j]):
                xr = lis[j-1]
                xl = lis[j]
            else:
                xl = lis[j-1]
                xr = lis[j]
            if xl >= l and xl < r and xr > r:
                flag = 1
                break
            if xr <= r and xr > l and xl < l:
                flag = 1
                break
        if flag == 1:
            break
    if(flag == 0):
        print("no")
    else:
        print("yes")