n = int(input())
if n < 3:
    print(-1)
else:
    arr = [2,3,1]
    for i in range(4,n):
        arr.append(i)
    print(*arr)