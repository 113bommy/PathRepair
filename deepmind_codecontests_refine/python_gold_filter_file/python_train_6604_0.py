from itertools import permutations as p
z=[];r=[*range(5)];ans=0
for i in range(5):z+=[list(map(int,input().split()))]
s=0
def function(z,k):
    global  s
    for i in range(0,len(k)-1,2):s+=z[k[i]][k[i+1]]+z[k[i+1]][k[i]]
    k.pop(0)
    if len(k)==1:return
    function(z, k)
for i in list(p(r,5)):
    s=0
    function(z,list(i))
    ans=max(ans,s)
print(ans)