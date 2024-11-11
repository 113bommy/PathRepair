n = int(input())
for i in range(n):
    m = int(input())
    lst = list(map(int, input().split()))
    lst = sorted(lst)
    flag = False
    for j in range(m - 1):
        if abs(lst[j] - lst[j + 1]) == 1:
            flag = True
            break
    if flag:
        print(2)
    else:
        print(1)
