n = int(input())
number = list(map(int, list(input())))
a = sorted(number[:n])
b = sorted(number[n:])

ans = 'Yes'
i = 0
while True:
    if a[0] > b[0]:
        if a[i] > b[i]:
            i += 1
        else:
            ans = 'No'
            break
    elif a[0] < b[0]:
        if a[i] < b[i]:
            i += 1
        else:
            ans = 'No'
            break
    else:
        ans = 'No'
        break
    if i == len(a):
        break
print (ans)