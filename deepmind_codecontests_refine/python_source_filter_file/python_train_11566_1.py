def lestnicy(lst):
    if all(x == lst[0] for x in lst):
        return lst
    a = list()
    for i in range(len(lst) - 1):
        if lst[i + 1] < lst[i]:
            a.append(lst[i])
    a.append(lst[len(lst) - 1])
    return a


n = int(input())
b = [int(j) for j in input().split()]
print(len(lestnicy(b)))
print(*lestnicy(b))
