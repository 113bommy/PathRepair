arr = list(map(int,input().split(' ')))
flag  = False
for i in range(arr[0]+1):
    if (arr[0] -i +arr[1] - i == arr[2] and (arr[1] - i > 0 ) and (arr[0] -i > 0 )):
        print(*[i,arr[1] - i,arr[0] -i] , sep = " ")
        flag  = True
        break
if not flag:
    print("Impossible")
    