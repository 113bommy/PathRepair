arr = [int(i) for i in input().split()]
arr.sort()
c = 0
for i in range(2):
    if arr[i]==arr[i+1]:
        c += 1
print(c)