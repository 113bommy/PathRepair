x = int(input())
fa = [1]*(x+1)
pw = [1]*(x+1)
md = int(1e9+7)
for n in range(1, x+1):
    fa[n] = (fa[n-1]*n) % md
    pw[n] = (pw[n-1]*2) % md

print(fa[n]-pw[n-1])
