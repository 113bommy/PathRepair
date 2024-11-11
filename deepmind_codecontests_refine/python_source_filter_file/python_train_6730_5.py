n = int(input())
x = list(map(int, input().split()))
[Min, Max, Mid] = [min(x), max(x), max(x)-1]
if (Max-Min < 2):print(n);print(*x);exit
[nMin, nMax, nMid] = list(map(x.count, [Min, Max, Mid]))
[nfMinMax, nfMid] = [min(nMin, nMax), nMid//2]
nf = max(nfMinMax, nfMid); b = ((nf==nfMid) or -1)
nMin += nf * b; nMax += nf * b; nMid += -2 * nf * b
print(n - 2*nf);print(*([Min]*nMin + [Max]*nMax + [Mid]*nMid))