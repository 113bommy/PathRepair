T = int(input())
for i in range(T):
    n = int(input())
    arr = [int(i) for i in input().split(" ")]
    left_mark = [False]*n
    right_mark = left_mark.copy()
    min_ = n + 2
    for j, i in enumerate(arr):
        if i < min_:
            min_ = i
        else:
            left_mark[j] = True
    min_ = n + 2
    for j, i in enumerate(arr[::-1]):
        if i < min_:
            min_ = i
        else:
            right_mark[n - 1 - j] = True
    for j, i in enumerate(right_mark):
        if right_mark[j] and left_mark[j]:
            print("Yes")
            for k, i in enumerate(arr[:j]):
                if i < arr[j]:
                    print(k, end=" ")
                    break
            print(j, end=" ")
            for k, i in enumerate(arr[j+1:]):
                if i < arr[j]:
                    print(k+j+1)
                    break
            break
    else:
        print("No")

    
    
