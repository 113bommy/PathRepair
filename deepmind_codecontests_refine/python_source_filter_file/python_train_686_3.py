import sys
input()
k=list(map(int,input().split()))
m=list(map(int,input().split()))
k=sorted(k)
m=sorted(m)
mini=10
for i in k:
    if i in m and i<mini:
        mini=i
if mini!=-1:
    print(mini)
    sys.exit()
p=min(k[0],m[0])
l=max(k[0],m[0])
print(str(p)+str(l))
