from collections import Counter
n = int(input())
k = Counter(map(int, input().split()))
m = int(input())
ls1 = list(map(int, input().split()))
ls2 = list(map(int, input().split()))
cntr = 0
j = 0
cntr2 = 0
for i in range(m):
    if k[ls1[i]] > cntr:
        cntr = k[ls1[i]]
        cntr2 = k[ls2[i]]
        j = i+1
    elif k[ls1[i]] == cntr:
        if k[ls2[i]] > cntr2:
            cntr2 = k[ls2[i]]
            j = i+1
print(j)
