def mlt(): return map(int, input().split())
def arp(): return [*mlt()]


x, y, d = mlt()
#
z = []
for n in range(x):
    z += arp()

x = x*y
md = z[x//2]
sm = 0
for n in z:
    sm += abs(md-n)
    if abs(md-n) % d != 0:

        print(-1)
        exit(0)

print(sm//d)
