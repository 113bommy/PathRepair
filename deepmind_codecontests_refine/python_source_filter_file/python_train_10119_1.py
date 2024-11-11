from itertools import permutations 
n, a = map(int,input().split())
lis=[]
mx=0
mi=100000000
ans=10000000
perm = permutations([i for i in range(1,a+1)]) 
for i in range(n):
    b = list(input())
    lis.append(b)
for i in perm:
    mx=0
    mi=100000000       
    for k in lis:
        now=''
        for j in i:
            now +=k[j-1]    
        mx = max(mx,int(now))
        mi = min(mi,int(now))
    ans = min(ans,mx-mi)
print(ans)           
                 



