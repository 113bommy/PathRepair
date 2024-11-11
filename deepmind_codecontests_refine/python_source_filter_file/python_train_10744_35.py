for __ in range(int(input())):
    arr = [int(s) for s in input().split()]
    arr.sort()
    if arr[2] - 2 > arr[0]+arr[1]:
        print('No')
    else:
        print('Yes')
      