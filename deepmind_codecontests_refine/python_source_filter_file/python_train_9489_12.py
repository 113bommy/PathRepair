n = int(input())
li = list(map(int, input().strip().split()))
for i in range(len(li)):
    l = len(li)
    temp = sorted(li)
    if temp == li:
        break
    left = li[0:l//2]
    right = li[l//2:l]
    left_length = 1
    right_length = 1
    for i in range(len(left)-1):
        if left[i+1] > left[i]:
            left_length += 1
        else:
            break
    for i in range(len(right)-1):
        if right[i+1] > right[i]:
            right_length += 1
        else:
            break
    if left_length > right_length:
        li = li[0:l//2]
    else:
        li = li[l//2:l]
print(len(li))


