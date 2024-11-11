xs = list(map(int, input().split(" ")))

b = bin(xs[0])[2:]
k = xs[1]
r = b.count('1')

ks = []

for i, q in enumerate(reversed(list(b))):
    if q == '1':
        ks.append(i)

if k < len(ks):
    print("NO")
else:
    stack = ks
    ans = []
    p = 0
    q = len(ks)
    while q < xs[1] and len(stack):
        x = stack.pop()
        if x == 0:
            ans.append(0)
        else:
            stack.append(x - 1)
            stack.append(x - 1)
            q += 1
    if q != k:
        print("NO")
    else:
        ans = ans + stack
        ans = " ".join(list(map(lambda x: str(2 ** x), ks)))
        print("YES")
        print(ans)
