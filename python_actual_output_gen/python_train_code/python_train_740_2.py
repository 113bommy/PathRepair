n, m = [int(i) for i in input().split()]
a, b = [int(i) for i in input().split()]
c, d = [int(i) for i in input().split()]
if (a + c < n and max(b, d) < m):
    print("YES")
elif (a + c <= m and max(b, d) <= n):
    print("YES")
elif (a + d <= m and max(b, c) <= n):
    print("YES")
elif (a + d <= n and max(b, c) <= m):
    print("YES")
elif (b + c <= m and max(a, d) <= n):
    print("YES")
elif (b + c <= n and max(a, d) <= m):
    print("YES")
elif (b + d <= m and max(a, c) <= n):
    print("YES")
elif (b + d <= n and max(a, c) <= m):
    print("YES")
else:
    print("NO")