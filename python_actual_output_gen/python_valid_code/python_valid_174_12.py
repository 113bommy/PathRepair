length, changes = map(int, input().split())
arr = list(map(int, input().split()))
flag = True
stop = False
index = 0
if arr[0] > 0:
    for x in range(changes):
        arr[0] *= -1
else:
    while flag:
        try:
            for index, x in enumerate(range(0, changes)):
                if changes <= length:
                    flag = False

                if stop:
                    arr[pos] *= -1
                elif arr[x] < 0:
                    arr[x] *= -1
                else:
                    pos = arr.index(min(arr))
                    arr[pos] *= -1
                    stop = True
                    flag = False
        except IndexError:
            changes = changes - (index + 1)
print(sum(arr))