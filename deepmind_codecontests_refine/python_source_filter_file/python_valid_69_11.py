
p_2 = [str(2**k) for k in range(40)]
def cost(e, n):
    cst = 0
    cur = 0
    for idx, c in enumerate(n):
        if cur < len(e) and c == e[cur]:
            cur += 1
        else:
            cst += 1
    cst += len(e) - cur
    #print(e, cst)
    return cst
t = int(input())
for _ in range(t):
    n = input()
    n = str(n)
    ans = 20
    for e in p_2:
        ans = min(ans, cost(e, n))
    print(ans)