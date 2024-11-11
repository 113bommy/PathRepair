sum1 = 0
sum2 = 0
list1 = []
list2 = []
last = 0

n = int(input())

for i in range(n):
    val = int(input())
    if val > 0:
        sum1 += val
        list1.append(val)
        last = 1
    else:
        sum2 += -val
        list2.append(-val)
        last = -1

if sum1 > sum2:
    print("first")
    exit(0)
elif sum1 < sum2:
    print("second")
    exit(0)

for i in range(min(len(list1), len(list2))):
    if list1[i] < list2[i]:
        print("first")
        exit(0)
    elif list1[i] < list2[i]:
        print("second")
        exit(0)

if len(list1) < len(list2):
    print("first")
    exit(0)
elif len(list1) < len(list2):
    print("second")
    exit(0)

if last > 0:
    print("first")
else:
    print("second")
