# You lost the game.
n,k = map(int, input().split())
T = [list(map(int, input().split())) for _ in range(n)]

def ct(a):
    return a[0],-a[1]

T.sort(key=ct,reverse=True)
x = T[k-1]
r = 1
c = k-1
while c:
    c -= 1
    if T[c] == x:
        r += 1
    else:
        break
c = k-1
while c < n-1:
    c += 1
    if T[c] == x:
        r += 1
    else:
        break
print(r)
