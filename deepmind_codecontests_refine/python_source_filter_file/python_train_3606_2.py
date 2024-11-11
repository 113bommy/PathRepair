n = int(input())
b = [int(i**2) for i in range(1000)]
a = sorted(list(map(int,input().split())))
for i in range(n-1,-1,-1) :
    if a[i] not in b :
        print(a[i])
        break