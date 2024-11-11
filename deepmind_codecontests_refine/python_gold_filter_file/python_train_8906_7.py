n = int(input())
a = [0 for i in range(1000)]
a[1] = 2
a[2] = 3
if n <4:
    print(n-1)
    exit()
i = 3
while True:
    a[i] = a[i-1] + a[i-2]
    if a[i] > n:
        print(i - 1)
        exit()
    i += 1