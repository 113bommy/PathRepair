arr=list(map(int,(input().split())))
if arr[2]==0:
    if arr[0]==arr[1]:
        print(0)
    elif arr[0]>arr[1]:
        print('+')
    else:
        print('-')
else:
    if (arr[0]+arr[2]>arr[1] and arr[1]+arr[2]>arr[0]):
        print('?')
    elif arr[0]+arr[2]>arr[1]:
        print('+')
    else:
        print('-')