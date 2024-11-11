n=int(input())
llist=[]
llist=list(map(int,input().split()))
c=0
d=0
dd=llist[1]-llist[0]
for i in range(n-1):
        if llist[i+1]-llist[i]==dd:
                c+=1
        if llist[i+1]==llist[0]:
                d+=1
if d==n-1:
        print(llist[0])
elif c==n-1:
        print(llist[n-1]+llist[1]-llist[0])
else:
        print(llist[n-1])