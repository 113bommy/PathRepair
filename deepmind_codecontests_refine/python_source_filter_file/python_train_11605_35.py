a, m = map(int, input().split())

r = a
ans = 0
for i in range(10**6):
    r += r % m

    if r % m == 0:
        ans = 1

if ans:
    print("YES")
else:
    print("NO")
