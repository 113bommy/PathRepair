n = int(input())
A = [list(map(int, input().split())) for _ in range(n)]
P = []
N = []
for x in A:
    if x[0] < 0:
        N = N + [x]
    else:
        P = P + [x]

def ct(a):
    return a[0]

P.sort(key=ct)
N.sort(key=ct,reverse=True)
ln = len(N)
lp = len(P)

r = 0
if ln < lp:
    for i in range(ln):
        r += N[i][1]
    for i in range(min(lp,ln+1)):
        r += P[i][1]
elif ln > lp:
    for i in range(lp):
        r += P[i][1]
    for i in range(min(ln,lp+1)):
        r += N[i][1]
else:
    for i in range(ln):
        r += N[i][1]
    for i in range(lp):
        r += P[i][1]
print(r)
