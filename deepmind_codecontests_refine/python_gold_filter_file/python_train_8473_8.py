n=int(input());
a=list(map(int,input().split()));
num=[0]*10;
for k in a:
    if(k==5 or k==7):
        print(-1);
        exit(0);
    num[k]+=1;
p=min(num[1],num[2],num[4]);
num[1]-=p;num[2]-=p;num[4]-=p;
q=min(num[1],num[3],num[6]);
num[1]-=q;num[3]-=q;num[6]-=q;
k=min(num[1],num[2],num[6]);
num[1]-=k;num[2]-=k;num[6]-=k;
for i in range(7):
    if(num[i+1]):
        print(-1);
        exit(0);
for i in range(p):
    print(1,2,4);
for i in range(q):
    print(1,3,6);
for i in range(k):
    print(1,2,6);