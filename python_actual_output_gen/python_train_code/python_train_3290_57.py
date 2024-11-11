nb_test = int(input())
ans = "NO"
for _ in range(nb_test):
    name, *vals = input().split()
    x, y  = map(int, vals)
    if y > x > 2400:
        ans = "YES"
        break
print(ans)

