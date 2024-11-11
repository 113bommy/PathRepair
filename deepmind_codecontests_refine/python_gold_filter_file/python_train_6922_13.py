n1, n2 = map(int, input().split())
k, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
k-=1
if a[k] < b[-m]:
    print("YES")
else:
    print("NO")
