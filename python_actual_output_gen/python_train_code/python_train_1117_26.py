n, m = map(int, input().split())
h = list(map(int, input().split()))

s=set()
for _ in range(m):
    a, b = map(int, input().split())
    a_h=h[a-1]
    b_h=h[b-1]
    if a_h>=b_h:
        s.add(b)
    if a_h<=b_h:
        s.add(b)

ans = n-len(s)
print(ans)

