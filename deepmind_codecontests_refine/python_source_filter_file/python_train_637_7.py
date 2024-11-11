n,m = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
k = 0
l = 0
kk = 0
lk = 0
for i in a:
    if i%2==0:
        l+=1
for i in b:
    if i%2==0:
        lk+=1
k = n - l
kk = m - lk
print(min(k,l) + min(kk,lk))