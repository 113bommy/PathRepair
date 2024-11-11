n, m = map(int, input().split())
arr = [False]*(n+1)
for i in range(m):
    a, b = map(int, input().split())
    arr[a] = arr[b] = True

i = 1
while i < n + 1 and not arr[i-1]: i+=1

print(n-1)
for j in range(1, n+1):
    if j != i:
        print(i, j)