n = int(input().strip())
p = {1:None}
check = {1:0}
for i in range(2, n+1):
    p[i] = int(input().strip())
    if p[i] not in check:
        check[p[i]] = 0
    if p[p[i]] is not None:
        check[p[p[i]]] -= 1
    check[p[i]] += 1
    p[p[i]] = None
sol = "Yes" if len(list(1 for v in check.values() if v<3)) == 0 else "No"
print(sol)
