from operator import itemgetter

N = int(input())
L = [[int(x) for x in input().split()] for _ in range(N)]


for i in range(N):
    L[i].append(L[i][1]-L[i][0])
    
L.sort()
L.sort(key=itemgetter(1))
L.sort(key=itemgetter(2))
    

la = L[0][0]
ra = L[0][1]
lb = L[1][0]
rb = L[1][1]
ans = L[-1][2]+1
for i in range(2, N):
    ta = max(0, min(ra, L[i][1])-max(la, L[i][0])+1) + rb-lb+1
    tb = max(0, min(rb, L[i][1])-max(lb, L[i][0])+1) + ra-la+1
    tc = max(0, min(ra, rb)-max(la,lb)+1) + L[i][1]-L[i][0]+1
    if max(ta, tb, tc) == ta:
        la = max(la, L[i][0])
        ra = min(ra, L[i][1])
    elif max(ta, tb, tc) == tb:
        lb = max(lb, L[i][0])
        rb = min(rb, L[i][1])
    else:
        la = max(la, lb)
        ra = min(ra, rb)
        lb = L[i][0]
        rb = L[i][1]
        
ans = max(ans, max(0, ra-la+1) + max(0, rb-lb+1))


print(ans)