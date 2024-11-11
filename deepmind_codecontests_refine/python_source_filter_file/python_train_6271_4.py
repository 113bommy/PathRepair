printn = lambda x: print(x,end='')
inn = lambda : int(input())
inl   = lambda: list(map(int, input().split()))
inm   = lambda:      map(int, input().split())
ins = lambda : input().strip()
DBG = True # and False
BIG = 10**18
R = 10**9 + 7

def ddprint(x):
  if DBG:
    print(x)

digs = ["1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"]

def chg(pat,c):
    dig = digs[c]
    cnt = 0
    for i in range(7):
        if pat[i]=='0' and dig[i]=='1':
            cnt += 1
        if pat[i]=='1' and dig[i]=='0':
            return 9
    return cnt

n,k = inm()
pats = []
chgh = {}
for i in range(n):
    p =ins()
    a = []
    for m in range(10):
        a.append(chg(p,m))
    chgh[p] = a
    pats.append(p)

d = [[0]*(k+1) for i in range(n+1)]
d[n][0] = 1
for i in range(n-1,-1,-1):
    p =pats[i]
    for j in range(k+1):
        if d[i+1][j]==0:
            continue
        for m in range(10):
            v = chgh[p][m] # chg(p,m)
            if v<9 and j+v<=k:
                d[i][j+v] = 1
if d[0][k]==0:
    print(-1)
    exit()
ans = []
x = k
for i in range(n):
    p = pats[i]
    for m in range(9,-1,-1):
        v = chgh[p][m] #  chg(p,m)
        if x-v>=0 and d[i+1][x-v]==1:
            ans.append(str(m))
            x -= v
            break
print(''.join(ans))
