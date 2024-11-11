n,m=map(int,input().split())
kd=n//2
ko=n%2
for i in range(n//2):
    if (kd+ko)%m==0: print(kd+ko); break
    kd-=1
    ko+=2
else: print(-1)