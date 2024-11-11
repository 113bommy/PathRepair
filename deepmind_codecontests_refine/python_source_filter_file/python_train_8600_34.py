from math import ceil
n=int(input())
ans=[-1]*17
ans[0]=0
for i in range(1,17):
    for j in [4,6,9]:
        if i>=j and ans[i-j]!=-1:
            ans[i]=max(ans[i-j]+1,ans[i])
            
for i in range(n):
    x=int(input())
    if x<16:
        print(ans[x])
    else:
        t=ceil((x-16)/4)+1

        print(t+ans[x-4*t])
        
        

