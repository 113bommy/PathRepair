n = int(input())
#n, m = map(int, input().split())
#s = input()
#c = list(map(int, input().split()))
if n % 2 == 1:
    print(-1)
else:
    a = list(range(1, n + 1))
    for i in range(0, n, 2):
        a[i], a[i + 1] = a[i + 1], a[i]
    print(a)