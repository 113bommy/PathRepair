# for _ in range(int(input())):
#     lst = [int(i) for i in input().split()]
#     if lst[2] == lst[0]+lst[1]:
#         print(lst[0], lst[1], lst[3])
#     else:
#         print(lst[0], lst[1], lst[2])


for _ in range(int(input())):
    n = int(input())
    lst = input().split()
    a = [lst[0][0]]
    f = lst[0][0]
    for i in lst:
        if f != i[0]:
            a.append(i[0])
        else:
            a.append(i[1])
        f = i[1]
    ans = "".join(a)
    if len(a) < n:
        print(ans+'b')
    else:
        print(ans)
