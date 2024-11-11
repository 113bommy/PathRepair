n,m = map(int,input().split())
k= input().split()
a=[int(i) for i in k]
a.sort()
a.reverse()
mi=1001
for i in range (1,len(a)-n+1):
    mi=min(mi,a[i]-a[i+n-1])
print(mi)