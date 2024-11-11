n = int(input())
a = [int(x) for x in input().split()]
a.sort()
if (n % 2 == 1):
     print(a[round(n / 2) - 1])
else:
    print(a[round(n / 2)])
