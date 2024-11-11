na, nb = map(int, input().split())
k, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

if a[k] < b[0]:
    print("YES")
else:
    print("NO")
