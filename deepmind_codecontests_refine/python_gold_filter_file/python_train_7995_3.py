n,m=map(int, input().split())
a=list(map(int, input().split()))
a.sort()
b=[a[i+1]-a[i] for i in range(m-1)]
b.sort(reverse=True)
print(sum(b[n-1:]))
