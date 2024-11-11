for _ in range(int(input())):
    n = int(input())
    lst = [int(i) for i in input().split()]
    lst.sort()
    res = list()
    for i in range(len(lst)):
        if i + 1 < len(lst):
            res.append(abs(lst[i + 1] - lst[i]))
    print(res[0])
