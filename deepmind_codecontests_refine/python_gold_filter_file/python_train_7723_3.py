t = int(input())
for i in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]
    a = sorted(a)
    result = 0
    for i in range(n):
        if n - i >= a[i]:
            if a[i] > result:
                result = a[i]
        elif n - i > result:
            result = n - i
    print(result)
