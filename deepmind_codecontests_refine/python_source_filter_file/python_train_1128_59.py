n=int(input())
a=list(map(lambda x:min(int(x)//400,8),input().split()))
cat=[0]*8
f=0
for ai in a:
    if ai < 8:
        cat[ai]=1
    if ai == 8:
        f+=1
print(str(max(sum(cat),1))+' '+str(min(sum(cat)+f,8)))