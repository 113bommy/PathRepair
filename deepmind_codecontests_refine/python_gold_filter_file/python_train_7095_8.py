n,a,x,b,y=map(int,input().split())
lol=0
i=0
l1=[]
l2=[]
while a!=x:
    l1.append(a)
    a+=1
    if(a)>n:
        a=1
    if(a==x):
        l1.append(a)
    #print(a)
i=0
while b!=y:
    l2.append(b)
    b-=1
    if(b)<=0:
        b=n
    if(b==y):
        l2.append(b)
#print(l1,l2)
for i in range(min(len(l1),len(l2))):
    if(l1[i]==l2[i]):
        lol=1
if(lol==1):
    print("YES")
else:
    print("NO")