n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))
a.sort()
b.sort()
diff = 2*n-2*m
j = 0
ans = [(2*n, 2*m)]
for i in range(n):
    while j < m:
        if b[j] <= a[i]-1:
            j += 1
        else:
            break
    ap = 2*(i) + 3*(n-i)
    bp = 2*(j) + 3*(m-j)
    if ap-bp > diff:
        diff = ap-bp
        ans = [(ap, bp)]
    elif ap-bp == diff:
        ans.append((ap, bp))
fans = max(ans, key=lambda x: x[0])
print(str(fans[0]) + ':' + str(fans[1]))
