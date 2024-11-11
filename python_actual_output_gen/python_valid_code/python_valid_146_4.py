a=int(input())
ans=0;z=[]
for i in range(1,82):
    s=0
    p=a-i
    while p>0:s+=p%10;p//=10
    if s==i:ans+=1;z+=[a-i]
print(ans,"\n ".join(map(str,z)),sep="\n")