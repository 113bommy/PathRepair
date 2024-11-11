import sys
input = sys.stdin.readline

N = int(input())
S = [input()[:-1] for _ in range(N)]
rl1, rl2 = [], []

for Si in S:
    l, r = 0, 0
    
    for i in range(len(Si)):
        if Si[i]=='(':
            l += 1
        else:
            if l==0:
                r += 1
            else:
                l -= 1
    
    if l-r>=0:
        rl1.append((r, l))
    else:
        rl2.append((r, l))
    
rl1.sort(key=lambda t: t[0])
rl2.sort(key=lambda t: t[1], reverse=True)
rl3 = rl1+rl2
bal = 0

for r, l in rl3:
    bal -= r
    
    if bal<0:
        print('No')
        exit()
    
    bal += l

if bal==0:
    print('Yes')
else:
    print('No')