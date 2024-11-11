import math
n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
aa=0;bb=0;common=0
for i in range(n):
    if a[i]==1 and b[i]==1:
        common+=1
    elif a[i]==1:
        aa+=1
    elif b[i]==1:
        bb+=1
print(str(aa)+" "+str(bb))
if aa==0 and common==0:
    print(-1)
elif aa==0:
    print(-1)
else:
    extra=bb+1
    print(math.ceil(extra/aa))