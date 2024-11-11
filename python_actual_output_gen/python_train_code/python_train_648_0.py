p, k = map(int, list(input().split()))
c = []
while p:
    c.append( abs(p % (-k)) )
    p = (p - p % k) // (-k)

print(len(c))
print(*c)


