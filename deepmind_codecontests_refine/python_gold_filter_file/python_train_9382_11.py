n = int(input())
a = [int(_) & 1 for _ in input().split()]
v = [a[0]]
for i in range(1, n):
    if v and v[-1] == a[i]:
        v.pop()
    else:
        v.append(a[i])
print("NO" if len(v) > 1 else "YES")
