def root(lst):
    a = list()
    for elem in lst:
        a.append(9 * (elem[0] - 1) + elem[0])
    return a


n = int(input())
b = list()
for i in range(n):
    k, x = [int(j) for j in input().split()]
    b.append([k, x])
print(root(b))
