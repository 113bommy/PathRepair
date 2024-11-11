k=[0]*1001
def dfs(x):
    k[x]+=1
    for i in z[x]:
        if not(k[i]):dfs(i)
a,b=map(int,input().split())
z=[]
for i in range(a+1):z+=[[]]
for i in range(b):
    x,y=map(int,input().split())
    z[x].append(y)
    z[y].append(x)
dfs(1)
if sum(k)!=a-1!=b:print("no")
else:print("yes")
