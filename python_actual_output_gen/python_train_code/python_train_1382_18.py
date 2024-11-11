num = input()
a = []


def get_the_data(count, num, arr):
    for i in range(0, len(num)):
        if num[i] == ' ':
            arr.append(int(num[count:i]))
            count = i+1
        elif i == len(num)-1:
            arr.append(int(num[count:len(num)]))
    return arr


arr = get_the_data(0, num,  a)
arr.sort()
if arr[0] <= 2 or arr[1] <= 2:
    print(0)
else:
    time = 0
    first = True
    while arr[0] > 0 and arr[1] > 0:
        if arr[0] == 1 or arr[0] == 2:
            first = True
        elif arr[1] == 1 or arr[1] == 2:
            first = False

        if first == True:
            arr[0] += 1
            arr[1] -= 2
        else:
            arr[1] += 1
            arr[0] -= 2
        time += 1

    print(time)


