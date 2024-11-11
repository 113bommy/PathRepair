f = lambda: map(int, input().split())
n,h = f()
mA,B = 0,[]
for _ in range(n):
    a,b = f()
    mA = max(mA,a)
    B.append(b)
B = sorted([i for i in B if i > mA], reverse=True)
ans = 0
while h>0:
    if not B:
        ans += h//mA
        break
    else:
        h -= B[0]
        B.pop(0)
        ans += 1
print(ans)
