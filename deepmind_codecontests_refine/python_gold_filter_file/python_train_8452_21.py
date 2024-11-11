for _ in range(int(input())):
    arr = [int(j) for j in input().split()]
    swaps = arr[1]
    position = abs(arr[2] - arr[3])
    while arr[0] - 1 > position and swaps != 0:
        position += 1
        swaps -= 1
    print(position)