n = input()
m = input()
c = set(m)
ans = 0
for colour in c:
    nc = n.count(colour)
    mc = m.count(colour)
    if nc == 0:
        ans = -1
        break
    else:
        ans += min(nc, mc)
print(ans)