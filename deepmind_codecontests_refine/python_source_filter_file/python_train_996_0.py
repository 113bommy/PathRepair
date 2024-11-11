ab = list(map(int, input().split()))
a = ab[0]
b = ab[1]
cd = list(map(int, input().split()))
c = cd[0]
d = cd[1]
list1 = []
list2 = []
counter1 = 0
counter2 = 0

if a + b > c + d:
    for i in range(a + b):
        list1.append(a * counter1 + b)
        counter1 += 1
    for i in list1:
        if (i - d) % c == 0 and (i - d) > 0:
            print(i)
            break
        if list1.index(i) == len(list1) - 1:
            print(-1)
            break
else:
    for i in range(c + d):
        list2.append(c * counter2 + d)
        counter2 += 1
    for i in list2:
        if (i - b) % a == 0 and (i - b) > 0:
            print(i)
            break
        if list2.index(i) == len(list2) - 1:
            print(-1)
            break

