n=int(input())
k=500000
a = list(map(int,input().split()))
for i in a:
    if abs(500000-i)<=k:
        k=abs(500000-i)
        l=i
if (500000-l)>=0:
    print(int(l-1))
else:
    print(1000000-l)
