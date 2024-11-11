t = int(input())
while t:
    n = int(input())
    arr = list(map(int, input().split()))
    sum = 0
    c=0
    for i in range(n):
        if arr[i]==0:
            arr[i]=1
            c = c + 1

    for i in range(n):
        sum = sum + arr[i]

    if sum==0:
        print(c + abs(sum)+1)
    else:
        print(c)
    t = t - 1
