n, k = [int(x) for x in input().split()]
res = int(n//k)
if res % 2 == 1:
    print("YES")
else:
    print("NO")
