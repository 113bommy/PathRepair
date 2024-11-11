n,m = map(int,input().split())
a = sorted(list(map(int,input().split())),reverse=True)
print("YNeos"[sum(a[i]<sum(a)/(4*m)for i in range(m))<m::2])