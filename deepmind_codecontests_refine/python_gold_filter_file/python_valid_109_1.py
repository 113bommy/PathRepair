t = int(input())
for _ in range(t):
    n = int(input())
    arr = [int(i) for i in list(input())]
    count = 0
    for i, e in enumerate(arr):
        if e: 
            count += e + 1
            if i == n-1: count -= 1
    print(count)