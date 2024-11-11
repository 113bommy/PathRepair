n = int(input())
L,R = [0]*n,[0]*n
for i in range(n):
    L[i],R[i] = map(int,input().split())
    R[i] += 1

M = L.index(max(L))
m = R.index(min(R))

d = [R[i] - L[i] if M != i != m else 0 for i in range(n)]
ans = max(d) + max(R[m] - L[M], 0)
d[m] = R[m] - L[m]
d[M] = R[M] - L[M]
if m == M:
    print(ans)
    exit()
if n == 2:
    print(d[m] + d[M])
    exit()
a,b = [0]*(n-2),[0]*(n-2)
j = 0
for i in range(n):
    if m != i != M:
        a[j],b[j] = max(R[i]-L[M],0) , max(R[m]-L[i],0)
        j += 1
ab = sorted(list(zip(a,b)),reverse = True)
mb = [0]*len(a)
for i in range(len(a))[::-1]:
    if i == len(a)-1:
        mb[i] = ab[i][1]
    else:
        mb[i] = min(ab[i][1], mb[i+1])
for i in range(len(a) - 1):
    ans = max(ans,min(a[i],d[M]) + min(mb[i + 1],d[m]))
ans = max(ans , d[M] + min(mb[0], d[m]), min(a[len(a)-1],d[M]) + d[m])

print(ans)
