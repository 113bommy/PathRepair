f = lambda: list(map(int,input().split()))
n = int(input())
a = f()
if n&1:
    b = a[::-2]+a[1::2]
else:
    b = a[::-1]+a[::2]
print(*b)
