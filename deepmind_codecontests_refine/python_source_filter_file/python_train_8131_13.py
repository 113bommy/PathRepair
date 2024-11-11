n,k = map(int,input().split())
l = list(map(int,input().split()))
l = list(set(l))
l.sort()
c=0
for i in l:
    if k==0:
        break
    print(i-c)
    c+=i
    k-=1
if k:
    while(k):
        print(0)
        k-=1
