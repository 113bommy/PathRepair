n = int(input())
a = list(map(int,input().split()))
f=1
res=[]
if(a.count(1)!=n//3):
    f=0
elif(a.count(2)+a.count(3)!=a.count(4)+a.count(6)):
    f=0
elif(a.count(3)>a.count(6)):
    f=0
else:
    f=1
    for i in range(a.count(3)):
        res.append([1,3,6])
    for i in range(a.count(6)-a.count(3)):
        res.append([1,2,6])
    for i in range(a.count(2)-(a.count(6)-a.count(3))):
        res.append([1,2,4])
if(len(res)<n//3):
    f=0
if(f==0):
    print(-1)
else:
    for i in range(len(res)):
        print(*res[i])