####################################### Define
oo = int(1e9)
maxN = int(2e5 + 10)
rmq = [[0 for i in range(20)] for j in range(maxN)]
a = [0] * maxN
ans = [0] * maxN
lst = [0] * maxN
nxt = [0] * maxN
check = [False] * maxN
####################################### Functions
def get(lef, rig) :
    len = rig - lef + 1
    pw2 = 0
    while (1 << (pw2 + 1)) <= len: pw2 += 1
    return min(rmq[lef][pw2], rmq[rig - (1 << pw2) + 1][pw2])
####################################### Main
n, q = (int(s) for s in input().split())
inp = input().split()

flag = False
for i in range(1, n + 1) :
    a[i] = int(inp[i - 1])
    if a[i] == q :  flag = True
    if a[i] == 0: a[i] = oo
if flag == False:
    for i in range(1, n + 1) :
        if a[i] == oo :
            a[i] = q
            flag = True
            break

for i in range(1, n + 1) :
    for j in range(0, 19) :
        rmq[i][j] = oo

for i in range(1, n + 1) :
    rmq[i][0] = a[i];
    for j in range(0, 18) :
            if i + (1 << j) <= n:
                rmq[i][j + 1] = min(rmq[i][j], rmq[i + (1 << j)][j])
for i in range(1, n + 1) :
    if a[i] < oo and check[ a[i] ] == False :
        lst[ a[i] ] = i
        check[ a[i] ] = True
for i in range(1, maxN): check[i] = False
for i in range(n, 0, -1) :
    if a[i] < oo and check[a[i]] == False :
        tmp = get(lst[ a[i] ], i)
        if tmp < a[i] or flag == False :
            print("NO")
            exit()
        nxt[ a[i] ] = i;
        check[ a[i] ] = True

cur = [0]
for i in range(1, n + 1) :
    if a[i] < oo :
        ans[i] = a[i]
        if lst[ a[i] ] == i : cur.append(a[i])
        if nxt[ a[i] ] == i : cur.pop()
    elif len(cur) > 1 : ans[i] = cur[-1]

for i in range(2, n + 1) :
    if ans[i] == 0 : ans[i] = ans[i - 1]
for i in range(n - 1, 0, -1) :
    if ans[i] == 0 : ans[i] = ans[i + 1]

print("YES")
for i in range(1, n + 1):
    print(ans[i])

