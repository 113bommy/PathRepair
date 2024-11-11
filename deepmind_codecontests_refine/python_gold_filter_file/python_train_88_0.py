while True:
    n = int(input())
    if n==0: break
    a = [int(input()) for _ in range(n)]
    count = 0
    for i in range(n):
        for j in range(n)[:0:-1]:
            if a[j] < a[j-1]:
                a[j], a[j-1] = a[j-1], a[j]
                count+=1
    print(count)