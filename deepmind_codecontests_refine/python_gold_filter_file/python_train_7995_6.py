n,m = list(map(int, input().split()))
a=list(map(int, input().split()))
a.sort()
d=[a[i+1]-a[i] for i in range(m-1)]
d.sort()
print(sum(d[:m-n]) if m>n else 0)