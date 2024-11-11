na, nb = map(int, input().split())
k, m = map(int, input().split())
a = list(map(int, input().split()))
a = sorted(a)
b = list(map(int, input().split()))
b = sorted(b)
if(a[k-1] < b[0]):
    print("YES")
else:
    print("NO")