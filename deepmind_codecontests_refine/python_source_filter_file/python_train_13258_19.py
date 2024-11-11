s,n = map(int,input().split())
a = sorted(tuple(map(int,input().split())) for _ in range(n))
r = True
for c in a:
    if s < c[0]:
        r = False
        break
    else:
        s += c[1]
print(('NO','YES')[r])