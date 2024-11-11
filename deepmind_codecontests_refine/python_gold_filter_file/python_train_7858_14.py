N = int(input())
arr = list(map(int,input().split()))
arr1 = [0]*N
temp = temp1 = 1
for i in range(N-1):
    if arr[i] <= arr[i+1]:
        temp = temp + 1
    else:
        # print("hj")
        if temp1 < temp:
            # print(temp1,temp)
            temp1 = temp
        temp = 1
    if temp1 < temp:
        temp1 = temp
print(temp1)