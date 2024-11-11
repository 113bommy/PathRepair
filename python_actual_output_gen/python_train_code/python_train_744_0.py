n, k = map(int, input().split())

a = list(map(int, input().split()))
b = list(map(int, input().split()))

if a.count(0) > 1:
    print("Yes")
else:
    a[a.index(0)] = b[0]
    if a == a.sort():
        print("No")
    else:
        print("Yes")