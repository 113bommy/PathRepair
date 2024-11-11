na, nb = map(int, input().split())
k, l = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

if a[k - 1] < b[nb - l]:
    print("YES")
else:
    print("NO")
