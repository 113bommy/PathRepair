i1 = int(input())
i2 = list(map(int, input().strip().split()))
k1 = 1
k2 = 0
for j in range(len(i2)-1):
    if i2[j]<=i2[j+1]:
        k1 = k1+1
        if k1>k2:
            k2 = k1
    if i2[j]>i2[j+1]:
        k1=1
print(k2)