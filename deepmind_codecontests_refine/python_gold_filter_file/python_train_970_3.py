def root(Arr,i):
    while(Arr[i]!=i):
        Arr[i]=Arr[Arr[i]]
        i=Arr[i]
    return i
def Union(Arr,A,B):
    root_A= root(Arr,A)
    root_B=root(Arr,B)
    if size[root_B]<size[root_A]:
        Arr[root_B]=Arr[root_A]
        size[root_A]+=size[root_B]
    else:
        Arr[root_A]=Arr[root_B]
        size[root_B]+=size[root_A]
        
        
        
def Find(A,B):
    if root(Arr,A)==root(Arr,B):
        return True
    return False

n=int(input())
Arr=list(range(n))
size=[1]*(n)
lst=[]

f=int(input())
for i in range(f):
    A,B=map(int,input().split())
    if not Find(A-1,B-1):
        Union(Arr,A-1,B-1)


e=int(input())

enemy=[]
#print(enemy)
for x in range(e):
    a,b=map(int,input().split())
    enemy.append([a-1,b-1])
#print(enemy)
for i in range(n):
    if Arr[i]==i:
        lst.append([size[i],i])
lst=sorted(lst)[::-1]


ans=0
test=0
if e==0:
    print(lst[0][0])
else:
    for i in range(len(lst)):
        Root=lst[i][1]
        test=0
        for k in range(e):
            if root(Arr,enemy[k][0])==Root and root(Arr,enemy[k][1])==Root:
                test=1
                break
        if test==0:
            ans=lst[i][0]
            break
#print(enemy)
#print(lst)       
    print(ans)
