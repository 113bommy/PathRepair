def val(a, b, c, d, u, v):
    return (a + b <= u and max(c, d) <= v) or (c + d <= u and max(a, b) <= v)


a1, b1 = [int(x) for x in input().split()]
a2, b2 = [int(x) for x in input().split()]
a3, b3 = [int(x) for x in input().split()]

#a1, b1 = min(a1, b1), max(a1, b1)
#a2, b2 = min(a2, b2), max(a2, b2)
#a3, b3 = min(a3, b3), max(a3, b3)

if val(a2, a3, a3, b2, a1, b1) or val(a2, b3, a3, b2, a1, b1) or val(a2, a3, a3, b2, b1, a1) or val(a2, b3, a3, b2, b1, a1):
    print("YES")
else:
    print("NO")