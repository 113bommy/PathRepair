testcase_number = int(input())
for i in range(0, testcase_number):
    n = int(input())
    arr_list = list(map(int,input().split(" ")))
    positive_sum = 0
    negative_sum = 0
    arr_list.sort()
    for i in arr_list:
        if i < 0:
            negative_sum += i
        else:
            positive_sum += i
    if negative_sum + positive_sum == 0:
        print("NO")
        continue
    elif positive_sum > negative_sum:
        arr_list = arr_list[::-1]
    print("YES")
    print(*arr_list,sep=' ')



