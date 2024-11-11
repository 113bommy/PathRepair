n,m,k = map(int,input().split())
a = list(map(int,input().split()))
a = sorted(a)[::-1]
s = 0
if k>=m:
    print(0)
    exit()
for i in range(k):
    s+=a[i]
    if s+k-(i+1)>=m:
        print(i+1)
        exit()
print(-1)