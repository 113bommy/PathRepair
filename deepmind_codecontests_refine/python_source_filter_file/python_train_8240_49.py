def find_middle(arr, n=3):
    mid = 0

    for i in range(n):
        mid += arr[i]

    if (mid % 2 != 0):
    	mid -= 1
    mid /= 2

    return mid


n = int(input(""))
arr = []

for i in range(0, n):
    n = list(map(int, input().split(" ")))
    arr.append(n)

for i in range(0, len(arr)):
    print(int(find_middle(arr[i])))
