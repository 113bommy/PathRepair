ab = list(map(int, input().split()))
a = ab[0]
b = ab[1]
cd = list(map(int, input().split()))
c = cd[0]
d = cd[1]
list1 = []
list2 = []
counter1= 0
counter2 = 0

for i in range(max(a, d)):
    list1.append(counter1 * a + b)
    list2.append((counter2 * c + d))
    counter1 += 1
    counter2 += 1


for i in range(len(list1)):
    if int(list1[i]) in list2:
        print(list1[i])
        break
    if i == len(list1) - 1:
        print(-1)
        break