t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    sorted(a)
    count = 1
    temp = 0
    for i in range(n):
        if a[i] <= count:
            temp = i + 1
        count += 1
    print(temp+1)