n, arr, i = int(input()), [2, 3], 1
if n == 2:
    print(1)
elif n == 3:
    print(2)
else:
    a, ans = arr[i] + arr[i - 1], 2
    while (a < n):
        i += 1
        arr.append(a)
        a = arr[i] + arr[i - 1]
        ans+=1
    print(ans)
