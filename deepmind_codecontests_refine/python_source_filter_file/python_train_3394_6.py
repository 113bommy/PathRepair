n,A = map(int,input().split())
c = list(map(int,input().split()))
count = [0]*(1000005)
avail = [1]*(1000005)
avail[A] = -1
for i in range(n):
    if (c[i]==A):
        count[A] += 1
    else:
        if (count[c[i]]>=count[A] and avail[c[i]]==1):
            count[c[i]] += 1
        else:
            avail[c[i]] = -1
ans = -1
for i in range(1000005):
    if (avail[i]==1 and count[i]>=count[A]):
        ans = i
        break
print(ans)