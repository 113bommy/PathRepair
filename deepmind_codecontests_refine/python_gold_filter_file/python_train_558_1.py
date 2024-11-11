
n = int(input())
arr = list(map(int, input().split()))
l = [-1] * 5
for i in arr:
    if i == 0:
        l[0] = 0
    elif i == 100:
        l[1] = 100
    elif i < 10:
        l[2] = i
    elif i % 10 == 0:
        l[3] = i
    else:
        l[4] = i
l1 = []
if l[0] == 0:
    l1.append(str(l[0]))
if l[1] == 100:
    l1.append(str(l[1]))
if l[2] > -1:
    l1.append(str(l[2]))
if l[3] > -1:
    l1.append(str(l[3]))

if l[4] > -1 and l[3] == -1 and l[2] == -1:
    l1.append(str(l[4]))
print(len(l1))
print(' '.join(l1))