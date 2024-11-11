n = int(input())

a = [int(i) for i in input().split()]


counts = {}
max_cnt=0
max_value = -1
indd = -1
for ij in range(n):
    i = a[ij]
    if i not in counts:
        counts[i] = 0
    counts[i]+=1
    if counts[i]>max_cnt:
        max_cnt = counts[i]
        max_value = i
        indd = ij

print(n-max_cnt)
for i in range(indd+1, n):
    if a[i]!=max_value:
        if a[i]<max_value:
            print(1, i+1, i)
        else:
            print(2, i + 1, i)

for i in range(indd-1, -1, -1):
    if a[i]!=max_value:
        if a[i]<max_value:
            print(1, i+1, i+2)
        else:
            print(2, i + 1, i + 2)
