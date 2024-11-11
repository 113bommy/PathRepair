n,m = map(int,input().split())
arr = []
for _ in range(n):
    a,b = map(int,input().split())
    arr.append([a,b])
last = arr[0][1]
for i in range(1,len(arr)):
    if last == m:
        print('YES')
        break
    if last < arr[i][0]:
        print('NO')
        break
    last=max(arr[i][1],last)
else:
    if arr[len(arr)-1][1] >= m:
        print('YES')
    else:
        print('NO')





