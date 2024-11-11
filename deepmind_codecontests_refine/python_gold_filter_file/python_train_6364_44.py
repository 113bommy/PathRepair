n=int(input())
L=[int(x) for x in input().split()]
L.sort()

arr=[0,500500]

for i in range(1,101):
    Sum=0
    for x in L:
        if abs(x-i)>1:
            Sum+=abs(x-i)-1;
    if arr[1]>Sum:
            arr[1]=Sum
            arr[0]=i
print(arr[0],arr[1]);