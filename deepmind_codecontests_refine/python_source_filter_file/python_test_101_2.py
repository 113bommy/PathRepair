from itertools import accumulate
for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    st = input()
    red_arr = [0 for i in range(n+1)]
    blue_arr = [0 for i in range(n+1)]
    count = 0
    for i in range(n):
        if st[i] == 'B':
            if arr[i] <= 0:
                count +=1
                continue
            if arr[i] >n:
                arr[i] = n
            blue_arr[arr[i]] +=1
        else:
            if arr[i] > n:
                count+=1
                continue
            if arr[i] < 0:
                arr[i] = 1
            red_arr[arr[i]] +=1
    if count >0:
        print("NO")
        continue
    blue_berry = list(accumulate(blue_arr))
    red_arr = red_arr[::-1]
    red_chilly = list(accumulate(red_arr))
    flag = 0
    for i in range(1, n+1):
        if blue_berry[i] > i or red_chilly[i] > i:
            flag = -1
            break
    if flag == -1:
        print("NO")
    else:
        print("YES")
