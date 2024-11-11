temp = [int(x) for x in input().split()]
n = temp[0]
k = temp[1]
a = sorted([int(x) for x in input().split()])
for i in range(n-1, -1, -1):
    if k % a[i] == 0:
        print(k // a[i])
        break
