n,b=map(int,input().split())
d=list(map(int,input().split()))
l1=[]
mx=max(d)
for item in d:
    l1.append(mx-item)
    b-=(mx-item)
if b%n!=0 or b<0:
    print(-1)
else:
    for i in range(len(l1)):
        l1[i]+=(b/n)
    for item in l1:
        print(format(item,'.6f'))