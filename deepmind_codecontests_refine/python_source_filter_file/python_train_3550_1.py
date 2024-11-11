n=int(input())
a=list(map(int,input().split()))
m=int(input())
b=list(map(int,input().split()))
aa=[a[0]]
for i in range(1,n):
    aa.append(a[-1]+a[i])
bb=[b[0]]
for j in range(1,m):
    bb.append(b[-1]+b[j])
if aa[-1]!=bb[-1]:
    print(-1)
else:
    print(len(set(aa)&set(bb)))