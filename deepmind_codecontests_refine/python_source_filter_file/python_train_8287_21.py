n = int(input())
a = []
b = []
a.append(int(input()))
a.append(int(input()))
a.append(int(input()))
if n > 1:
    res = min(a[0], a[1])
    if n == 1: print(res)
    else:
        print((min(a[1], a[2]))*(n-2) + res)
else:
    print(0)
