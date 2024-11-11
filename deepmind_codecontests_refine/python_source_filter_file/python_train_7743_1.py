n,k=map(int,input().split())
x=input()
res=0
count=0
for i in range(n):
    if x[i]=='#':
        count+=1
        if count>res:
            res=count
    else:
        count=0
if res<k:
    print('Yes')
else:
    print('No')