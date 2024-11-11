n,m = map(int,input().split())
a = [list(map(int,input().split())) for i in range(n)]
count = [0]*(m+1)
for i in a:
    count[i[0]] += 1
l = [0]*n
ans = max(count)
s = set()
for i in range(m-1):
    M = max(count)
    ind = count.index(M)
    s.add(ind)

    for j in range(n):
        if a[j][l[j]] == ind:

            count[ind] -= 1
            while a[j][l[j]] in s:
                l[j] += 1
            count[a[j][l[j]]] += 1
    ans = min(ans,max(count))

print(ans)