n = int(input())
x = list(map(int, input().split()))
x.sort()
if n % 2 == 0:
    print(x[n // - 1])
else:
    print(x[n // 2])
