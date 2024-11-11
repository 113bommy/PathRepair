arr = [int(x) for x in input().split()]

if (arr[1]< arr[0] and arr[2]<arr[0]):
    print(-1)
elif(arr[1]<arr[0]):
    if (arr[2]%arr[0]==0):
        print(int(arr[2]/arr[0]))
    else:
        print(-1)
elif(arr[2]<arr[0]):
    if (arr[1]%arr[0]==0):
        print(int(arr[1]/arr[0]))
    else:
        print(-1)
else:
    print(int(arr[1]/arr[0]+arr[2]/arr[0]))
