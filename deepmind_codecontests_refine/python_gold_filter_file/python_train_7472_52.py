N = int(input())
S = [input() for _ in range(N)]

T = [0]*N
M = [0]*N
for i in range(N):
    res = 0
    idx = 0
    s = S[i]
    l = len(s)
    m = 0
    while idx<l:
        if s[idx]==')':
            res -= 1
            m = min(res,m)
        else:
            res += 1
        idx += 1
    
    M[i] = m
    T[i] = res

Tp = []
Tn = []
for i in range(N):
    if T[i]>=0:
        Tp.append([M[i], T[i]])
    else:
        Tn.append([M[i]-T[i], -T[i]])

Tp.sort(reverse = True)
Tn.sort(reverse = True)
res = 0
for m,t in Tp:
    if res<-m:
        print('No')
        exit()
    res += t

resn = 0
for m,t in Tn:
    if resn<-m:
        print('No')
        exit()
    resn += t
if res==resn:
    print('Yes')
else:
    print('No')