n,m = list(map(int, input().split()))
a=list(map(int, input().split()))
a.sorted()
d=[a[i+1]-a[i] for i in range(m-1)]
d.sorted()
print(sum(d[:m-n]) if m>n else 0)