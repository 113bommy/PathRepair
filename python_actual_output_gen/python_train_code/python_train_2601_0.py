n = input()
m = input()
c = set(n)
ans = 0
for colour in c:
    nc = n.count(colour)
    mc = m.count(colour)
    if mc == 0:
        ans = -1
        break
    else:
        ans += min(nc, mc)
print(ans)