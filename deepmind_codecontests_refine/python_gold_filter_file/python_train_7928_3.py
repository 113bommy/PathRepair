def binary_search(len_s, a, b):
    left = -1
    right = len_s + 1
    while left < right - 1:
        middle = (left + right) // 2
        flag = False
        for i in range(26):
            if a[i] > b[middle][i]:
                flag = True

        if flag:
            left = middle
        else:
            right = middle
    if right < len_s + 1:
        return right
    else:
        return []


q = int(input())
arr = [[0] * 26]
s = str(input())
index = 0
for elem in s:
    arr[index][97 - ord(elem)] += 1
    arr.append((arr[index].copy()))
    index += 1
arr.pop(len(arr) - 1)
n = int(input())
for i in range(n):
    s = str(input())
    str_arr = [0] * 26
    for c in s:
        str_arr[97 - ord(c)] += 1
    val = binary_search(q, str_arr, arr)
    print(val + 1)

