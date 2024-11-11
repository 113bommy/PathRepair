n = int(input())
arr = []
for i in range(n):
    arr.append(set([int(i) for i in input().split()][1:]))
x = arr[0]&arr[1]
for i in range(2,len(arr)):
    x &= arr[i]
print(*x)