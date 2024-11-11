n = int(input())
v = list(map(int,input().split()))
a = sorted(v)
for i in range(n-1):
    v[i+1]+=v[i]
    a[i+1]+=a[i]
v,a = [0]+v,[0]+a
#print(v,a)
for _ in range(int(input())):
    t,l,r = map(int,input().split())
    if t==1:
        print(v[r]-v[l-1])
    else:
        print(a[r]-a[l-1])