import collections
n = int(input())
a = list(map(int, input().split()))

count = collections.Counter(a)
maxnumber = count.most_common()[0][0]
maxcount = count.most_common()[0][1]

print(n-maxcount)
for i in range(n):
    if a[i] == maxnumber:
        index = i
        break

for i in range(index-1, -1, -1):
    if a[i+1] - a[i] == 0:
        continue
    elif a[i+1] - a[i] > 0:
        a[i] = a[i+1]
        print(1, i+1, i+2)
    else:
        a[i] = a[i+1]
        print(2, i+1, i+2)

for i in range(index, n-1):
    if a[i+1] - a[i] == 0:
        continue
    elif a[i+1] - a[i] > 0:
        a[i+1] = a[i]
        print(2, i+2, i+1)
    else:
        a[i+1] = a[i]
        print(1, i+2, i+1)
