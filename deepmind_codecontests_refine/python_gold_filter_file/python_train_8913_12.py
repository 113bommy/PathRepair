n=int(input())
L=list(map(int,input().split()))

n2=0
n1=0
for i in L:
    if i==1:
        n1+=1
    else:
        n2+=1

if n2<=n1:
    ans=n2+(n1-n2)//3
else:
    ans=n1

print(ans)
    
