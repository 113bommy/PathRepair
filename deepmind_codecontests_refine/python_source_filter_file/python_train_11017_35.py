n = int(input())
lis = list(map(int, input().split()))
if abs(max(lis)) >= abs(min(lis)):
    ind = lis.index(max(lis)) + 1
else:
    ind = lis.index(min(lis)) + 1
opere = []
if lis[ind-1] > 0:
    for i in range(1, n+1):
        opere.append([ind, i])
    for i in range(1, n):
        opere.append([i, i + 1])
else:
    for i in range(1, n+1):
        opere.append([ind, i])
    for i in range(1, n):
        opere.append([n-i, n-i-1])

print(2*n-1)
if opere:
    for i in opere:
        print(" ".join(list(map(str, i))))