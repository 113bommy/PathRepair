a, b, c = map(int, input().split(' '))
d, e, f = map(int, input().split(' '))

dist = (abs(a-d)**2+abs(b-e)**2)**0.5

maxx = max(c, f)
minn = min(c, f)

if maxx > minn + d:
    print((maxx-minn-dist)/2)

else:
    print(max(0, dist-c-f))
