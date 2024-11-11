n,d=map(int,input().split())
l=sorted([tuple(map(int,input().split())) for i in range(n)])
po=ki=ma=0
su=l[po][1]
for i in range(n):
    while l[po][0]<=l[i][0]-d: su-=l[po][1]; po+=1
    while ki<n-1 and l[ki+1][0]<l[po][0]+d: ki+=1; su+=l[ki][1]
    if su>ma: ma=su
print(ma)