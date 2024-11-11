n,m,v,p = map(int,input().split())
a = list(map(int,input().split()))

a.sort(reverse=True)

higher = a[p-1]
for i in range(p,n):
    if(a[i] == a[i-1]):
        higher += a[i]
        continue

    if(a[p-1]- a[i] > v):
        print(i)
        exit()

    if(higher - a[i]*(i-p+1) > min(n-v,i-p+1)*m):
        print(i)
        exit()

    higher += a[i]

print(n)