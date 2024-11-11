n = int(input())
array = list(map(int, input().split()))
if n == 1:
    print(1)
    exit(0)
s = sum(array)
for i in range(n):
    array[i] = (array[i], i+1)
array.sort()
count = 0
for i in range(1, n-1):
    if array[i][0]-array[i-1][0] != array[i+1][0]-array[i][0]:
        new_array = array.copy()
        new_array.pop(i-1)
        q = True
        for j in range(1, n - 2):
            if new_array[j][0] - new_array[j - 1][0] != new_array[j + 1][0] - new_array[j][0]:
                q = False
                break
        if q:
            print(array[i-1][1])
            exit(0)
        new_array = array.copy()
        new_array.pop(i)
        q = True
        for j in range(1, n - 2):
            if new_array[j][0] - new_array[j - 1][0] != new_array[j + 1][0] - new_array[j][0]:
                q = False
                break
        if q:
            print(array[i][1])
            exit(0)
        new_array = array.copy()
        new_array.pop(i+1)
        q = True
        for j in range(1, n - 2):
            if new_array[j][0] - new_array[j - 1][0] != new_array[j + 1][0] - new_array[j][0]:
                q = False
                break
        if q:
            print(array[i+1][1])
            exit(0)
        print(-1)
        exit(0)
print(array[0][1])