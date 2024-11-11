n, m, k = map(int,input().split())
a = [int(x) for x in input().split()]
b = [[] for i in range(k)]
for x in a:
    b[x%k].append(x)
maxl, maxi = len(b[0]),0
for i in range(k):
    if len(b[i])>maxl:
        maxl = len(b[i])
        maxi = i
if m<=maxl:
    print('Yes')
    print(' '.join(str(x) for x in b[maxi]))
else:
    print('No')

