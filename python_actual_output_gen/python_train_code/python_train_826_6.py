lst = list(map(int, input().split()))
b = lst[0]
a = lst[1]
k = 0
lst = []
while a != b:
    lst.append(a)
    if a % 2 != 0  and a % 10 != 1:
        print('No')
        break
    elif a < b:
        print('No')
        break
    elif a % 10 == 1:
        a = a // 10
        k += 1
    else:
        a = a // 2
        k += 1
    if a == b:
        lst.append(a)
        lst.reverse
        print('Yes')
        print(len(lst))
        for i in range(len(lst)):
            print(lst[i], end=' ')