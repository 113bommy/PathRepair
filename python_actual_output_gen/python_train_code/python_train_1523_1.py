n = int(input())
arr = list(map(int, input().split()))
brr = arr
t = 0
for i in range(n):
    t = arr[i] - 1
    brr[t] = i + 1
print(*brr)