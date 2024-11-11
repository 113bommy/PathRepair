n = int(input())
a = list(map(int,input().split()))
if n == 1:
    print(a[0])
elif n == 2:
    print(max(a))
else:
    a = a[::2]+a[1::2]
    v = (n+1)//2
    mm = 0
    a1 = [0]

    for i in range(n):
        a1.append(a1[-1]+a[i])
    for i in range(v):
        a1.append(a1[-1]+a[i])

    output = max([a1[i+v]-a1[i] for i in range(n)])
    print(output)