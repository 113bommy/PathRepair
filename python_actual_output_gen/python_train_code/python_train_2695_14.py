n = int(input())
arr = [int(i) for i in input().split()]
arr.sort()
a, b = 0, 0
print(arr[n-1] - arr[0], end=' ')
t = arr[0]
while arr[a] == t:
    a = a + 1
    if a == n:
        break
if t == arr[n-1]:
    r = 1
    if n > 2:
        r = n*(n-1)/4
    print(int(r))
    exit()
t = arr[n-1]
while arr[n-b-1] == t:
    b = b + 1
    if b == n:
        break
r = a*b
print(r)