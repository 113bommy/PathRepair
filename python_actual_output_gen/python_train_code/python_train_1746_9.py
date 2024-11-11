n=int(input())
am=1000000001
ab=0
bm=1000000001
bb=0
for i in range(n):
    a,b=map(int,input().split())
    if a>ab:
        ab=a
    if b<am:
        am=b
m=int(input())
for i in range(m):
    a,b=map(int,input().split())
    if a>bb:
        bb=a
    if b<bm:
        bm=b
print(max(max(0,ab-bm+1),max(0,bb-am+1)))

    
    
