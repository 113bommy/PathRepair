n,m=map(int, input().split())
a=list(map(int, input().split()))
a.sort()
b=[a[i+1]-a[i] for i in range(n-1)]
b.sort(reverse=True)
print(sum(b[m-1:]))
