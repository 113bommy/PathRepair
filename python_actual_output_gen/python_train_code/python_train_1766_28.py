n = int(input())
a = [int(x) for x in input().split()]
ans = 0
if a == [1, 0, 1]:
    print(1)
else:
    for i in range(3, n):
        if a[i] == 1 and a[i - 1] == 0 and a[i - 2] == 1:
            ans += 1
            a[i] = 0

    print(ans)
