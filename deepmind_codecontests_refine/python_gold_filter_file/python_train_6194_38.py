n = int(input())
arr = list(map(int,input().split()))
mini = arr[0]
for i in arr:
    if mini>i:
        mini = i
if mini==1:
    print(-1)
else:
    print(1)