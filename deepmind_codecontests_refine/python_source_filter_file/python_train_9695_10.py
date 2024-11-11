n = int(input())
a = [int(i) for i in input().split()]
ans = 0
while len(a) != 0:
    if a[0] in a[1:]:
        del a[1 + a[1:].index(a[0])]
        del a[0]
    else:
        j = min([(abs(a[0] - a[1:][i]), i) for i in range(len(a[1:]))])
        ans += j[0]
        del a[0]
        del a[j[1]]
print(ans)