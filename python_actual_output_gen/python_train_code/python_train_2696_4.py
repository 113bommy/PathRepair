n = int(input())
l1 = []
for i in range(n):
    l1.append([int(j) for j in input().split()])

l1.sort(key = lambda x:x[0])

l2 = []
l2.append(l1[0][1])
for i in range(1,n):
    if l1[i][1] >= l2[i-1]:
        l2.append(l1[i][1])
    else:
        l2.append(l1[i][0])

print(l2[n-1])
