n,B=map(int,input().split())
a=list(map(int,input().split()))
odd=0
even=0
poss=[]
for i in range(n-1):
    if(a[i]%2==0):
        even+=1
    else:
        odd+=1
    if(odd==even):
        poss.append(abs(a[i+1]-a[i]))
poss.sort()
# print(poss)
ans=0
i=0
# if(len(poss)>0):
#     B-=poss[i]
#     i+=1
while(i<len(poss) and B>0):
    B-=poss[i]
    if(B>=0):
        ans+=1
    i+=1
print(ans)
