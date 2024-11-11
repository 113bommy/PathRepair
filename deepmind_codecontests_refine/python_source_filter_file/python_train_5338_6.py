n = int(input())
 
l = list(map(int, input().split()))
l.sort()
ll = []

if (n == 1):
    print(0)
    print(l[0])
elif (n == 2):
    print(0)
    print(l[0], l[1])
elif (n % 2 == 0):
    j = 0
    buys = 0
    for i in range(n//2, n):
        ll.append(l[i])
        if (j < n // 2):
            ll.append(l[j])
            j += 1
    for i in range(1, len(ll) - 2):
        if ll[i - 1] < ll[i] < ll[i + 1]:
            buys += 1
    print(buys)
    for i in ll:
        print(i, end = " ")
 
else:
    j = 0
    buys = 0
    for i in range(n//2, n):
        ll.append(l[i])
        if (j < n // 2):
            ll.append(l[j])
            j += 1
    for i in range(1, len(ll) - 1):
        if ll[i - 1] > ll[i] < ll[i + 1]:
            buys += 1
    print(buys)
    for i in ll:
        print(i, end = " ")