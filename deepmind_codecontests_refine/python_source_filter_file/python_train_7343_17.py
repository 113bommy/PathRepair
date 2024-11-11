n = int(input())
a = list(map(int, input().split()))
for i in range(1, n):
    for j in range(i):
        if a[j+1]<a[j]:
            a[j], a[j+1] = a[j+1], a[j]
            print(j+1, j+2)