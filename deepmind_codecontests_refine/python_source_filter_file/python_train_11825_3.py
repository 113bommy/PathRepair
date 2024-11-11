n,l,r=map(int,input().split())
ar=[]
cnt=0
if(n<2):
    print(0)
    exit()
while(n>1):
    ar.append(n%2)
    cnt+=1
    n//=2
pw=[2**i for i in range(cnt-1,-1,-1)]
ans=0
pnt=0
for i in range(l,r+1):
    if i%2==1:
        ans+=1
        continue
    con=i//2
    for j in range(cnt):
        if con%pw[j]==0:
            ans+=ar[j]
            #print(i,ar[j])
            break
print(ans)
        
