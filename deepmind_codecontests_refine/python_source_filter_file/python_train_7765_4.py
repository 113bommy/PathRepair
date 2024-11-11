def competition(a, lst):
    s = sum(a)
    for elem in lst:
        if s <= elem[1]:
            if s >= elem[0]:
                return s
            else:
                return elem[1]
    return -1


n = int(input())
b = [int(i) for i in input().split()]
c = list()
m = int(input())
for z in range(m):
    l, r = [int(x) for x in input().split()]
    c.append([l, r])
print(competition(b, c))



