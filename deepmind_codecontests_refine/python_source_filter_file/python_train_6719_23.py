n, a = [int(x) for x in input().split()]
l = list(map(int, input().split()))
l1 = l[0: a - 1]
l2 = l[a:]
num = 0
if a - 1 >= n - a:
    for i in range(0, n - a - 1):
        if l1[-i - 1] == 1 and l2[i] == 1:
            num += 2
    l3 = l[0: 2 * a - n - 2]
    s = sum(l3)
    num += s
else:
    for i in range(0, a - 1):
        if l1[-i - 1] == 1 and l2[i] == 1:
            num += 2
    l3 = l[2 * a - 1:]
    s = sum(l3)
    num += s
num += l[a - 1]
print(num)