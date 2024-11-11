a = int(input())
list = input().split()
list2 = []
for elements in list:
    elements = int(elements)
    list2.append(elements)
count1 = int(list2.count(1))
count2 = int(list2.count(2))
count3 = int(list2.count(3))
count4 = int(list2.count(4))
count6 = int(list2.count(6))
if 5 in list2 or 7 in list2:
    print(-1)
elif (count2 + count3) != (count4 + count6):
    print(-1)
elif count2 < count4:
    print(-1)
elif (count2-count4) != (count6-count3):
    print(-1)
elif count1 != (a/3):
    print(-1)
else:
    if count4 != 0:
        print("1 2 4\n" * count4)
    if count3 != 0:
        print("1 3 6\n" * count3)
    if (count2-count4) != 0:
        print("1 2 6\n" * (count2 - count4))