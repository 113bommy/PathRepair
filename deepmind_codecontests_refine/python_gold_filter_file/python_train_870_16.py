l1 = []
l2 = []
n = int(input())
l3 = [int(number) for number in input().split(' ')]
for i in l3:
    for j in range(i):
        l2.append(0)
    l1.append(l2)
    l2 = list()
m = int(input())
for i in range(m):
    l4 = [int(num) for num in input().split(' ')]
    x = l4[0]
    y = l4[1]
    for j in range(len(l1[x - 1]) - y):
        if x < n:
            l1[x].append(0)
    for j in range(y - 1):
        if x - 2 >= 0:
            l1[x - 2].append(0)
    l1[x - 1] = list()
for i in l1:
    print(len(i))
