from collections import Counter


def divisors(lst):
    maximum = max(lst)
    c, q = Counter(lst), 1
    for elem in lst:
        if elem > q and c[elem] == 2:
            q = elem
    for elem in lst:
        if elem > q and maximum % elem != 0:
            q = elem
    return maximum, q


n = int(input())
a = [int(i) for i in input().split()]
print(divisors(a))
