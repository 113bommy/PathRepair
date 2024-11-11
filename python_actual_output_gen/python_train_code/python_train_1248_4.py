n = int(input())
arr = list(map(int, input().split()))
s = sum(arr) // 2
s1 = 0
for i in range(n):
    s1 += arr[i]
    if s1 >= s:
        print(i+1)
        break